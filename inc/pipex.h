/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:53:56 by julifern          #+#    #+#             */
/*   Updated: 2025/04/06 19:56:47 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "ft_printf/inc/ft_printf.h"
# include "libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
	int		infile;
	int		outfile;
	pid_t	pid;
}	t_cmd;

int		init_data(t_cmd **data);
char	init_pipes(t_cmd **data, char **argv, char **env);
void	init_struct(t_cmd **data);
void	close_fds(int fd1, int fd2);
void	close_all_fd(t_cmd **data);
void	free_all(t_cmd **data);
void	error_message(int n);

char	*search_path(char **path, char *cmd);
char	*get_env_path(char **env, char *cmd);
char	get_cmd(char **argv, char **env, t_cmd **data);

void	exec_cmd(char *path, char **cmd, char **env);
int		fork_process(t_cmd **data, char **env);

#endif
