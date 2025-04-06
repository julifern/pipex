/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 18:24:41 by julifern          #+#    #+#             */
/*   Updated: 2025/04/06 20:34:33 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(int n)
{
	if (n == 1)
	{
		perror("unset PATH ");
		exit(0);
	}
	else if (n == 2)
	{
		perror("Command failed ");
	}
}
