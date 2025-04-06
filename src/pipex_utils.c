/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:26:35 by julifern          #+#    #+#             */
/*   Updated: 2025/04/06 17:31:48 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	init_pipes(t_cmd **data, char **argv, char **env)
{
	data[0]->infile = open(*(argv + 1), O_RDONLY);
	if ((*data)->infile == -1)
	{
		perror("Infile ");
		return (-1);
	}
	data[1]->outfile = open(*(argv + 4),
			O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data[1]->outfile == -1)
	{
		perror("Outfile ");
		free_all(data);
		return (-1);
	}
	get_cmd(argv + 2, env, data);
	return (0);
}

void	init_struct(t_cmd **data)
{
	while (*data)
	{
		(*data)->cmd = NULL;
		(*data)->path = NULL;
		(*data)->infile = -1;
		(*data)->outfile = -1;
		(*data)->pid = -1;
		++data;
	}
}

void	close_fds(int fd1, int fd2)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 > -1)
		close(fd2);
}

void	close_all_fd(t_cmd **data)
{
	while (*data)
	{
		close((*data)->infile);
		close((*data)->outfile);
		++data;
	}
}

void	free_all(t_cmd **data)
{
	while (*data)
	{
		if ((*data)->cmd)
			ft_free_array((*data)->cmd, ft_count_array((*data)->cmd));
		if ((*data)->path)
			free((*data)->path);
		if ((*data)->infile > -1)
			close((*data)->infile);
		if ((*data)->outfile > -1)
			close((*data)->outfile);
		free(*data);
		*data = NULL;
		++data;
	}
}
