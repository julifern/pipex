/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:53:46 by julifern          #+#    #+#             */
/*   Updated: 2025/04/06 20:38:27 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_data(t_cmd **data)
{
	data[0] = malloc(sizeof(t_cmd));
	if (!data[0])
		return (1);
	data[1] = malloc(sizeof(t_cmd));
	if (!data[1])
	{
		free(data[0]);
		return (1);
	}
	data[2] = NULL;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*data[3];
	int		ret;

	ret = 0;
	if (argc != 5)
		return (0);
	ret = init_data(data);
	if (ret == 1)
		return (0);
	init_struct(data);
	ret = init_pipes(data, argv, envp);
	if (ret == -1)
	{
		free_all(data);
		error_message(2);
	}
	fork_process(data, envp);
	free_all(data);
	return (ret);
}
