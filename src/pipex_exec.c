/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:36:12 by julifern          #+#    #+#             */
/*   Updated: 2025/04/06 20:34:52 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *path, char **cmd, char **env)
{
	execve(path, cmd, env);
	ft_free_array(cmd, 2);
}

int	set_pipe(t_cmd *data1, t_cmd *data2)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (0);
	data1->outfile = pipefd[1];
	data2->infile = pipefd[0];
	return (1);
}

int	child_process(t_cmd *data, char **env)
{
	if (data->infile == -1 || data->outfile == -1)
		return (0);
	dup2(data->infile, 0);
	dup2(data->outfile, 1);
	close_fds(data->infile, data->outfile);
	exec_cmd(data->path, data->cmd, env);
	return (0);
}

int	create_child(t_cmd *data1, t_cmd *data2, char **env, t_cmd **tab)
{
	if (!data1 || (data2 && !set_pipe(data1, data2)))
		return (0);
	data1->pid = fork();
	if (data1->pid == 0)
	{
		if (data2)
			close_fds(data2->infile, data2->outfile);
		if (!child_process(data1, env))
		{
			free_all(tab);
			error_message(2);
		}
	}
	close_fds(data1->infile, data1->outfile);
	return (0);
}

int	fork_process(t_cmd **data, char **env)
{
	create_child(data[0], data[1], env, data);
	create_child(data[1], NULL, env, data);
	while (*data)
	{
		waitpid((*data)->pid, NULL, 0);
		++data;
	}
	return (1);
}
