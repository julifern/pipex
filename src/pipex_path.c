/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:38:46 by julifern          #+#    #+#             */
/*   Updated: 2025/04/06 20:41:45 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*search_path(char **path, char *cmd)
{
	char	*test_path;
	size_t	i;

	test_path = NULL;
	i = 0;
	if (!cmd)
		return (NULL);
	while (path[i])
	{
		test_path = ft_strjoin(path[i], cmd);
		if (!test_path)
			return (NULL);
		if (access(test_path, X_OK) == 0)
		{
			free(cmd);
			return (test_path);
		}
		i++;
		free(test_path);
		test_path = NULL;
	}
	return (NULL);
}

char	*get_env_path(char **env, char *cmd)
{
	int		i;
	char	**path;
	char	*tmp;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (ft_strlen(env[i]) < 6)
		error_message(1);
	tmp = ft_substr(env[i], 5, ft_strlen(env[i]) - 5);
	path = ft_split(env[i], ':');
	i = 0;
	free(tmp);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	tmp = search_path(path, ft_strjoin("/", cmd));
	if (!access(cmd, X_OK))
		tmp = ft_strdup(cmd);
	ft_free_array(path, ft_count_array(path));
	return (tmp);
}

char	get_cmd(char **argv, char **env, t_cmd **data)
{
	while (*data)
	{
		(*data)->cmd = ft_split(*argv, ' ');
		if (!(*data)->cmd || !*((*data)->cmd))
		{
			free_all(data);
			return (-1);
		}
		(*data)->path = get_env_path(env, (*data)->cmd[0]);
		if (!(*data)->path)
		{
			perror("cmd not found ");
			free_all(data);
			exit(127);
		}
		++argv;
		++data;
	}
	return (0);
}
