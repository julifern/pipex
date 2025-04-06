/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:31:41 by julifern          #+#    #+#             */
/*   Updated: 2025/02/07 15:35:20 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_array(void *array)
{
	void	**cpy;
	size_t	i;

	cpy = array;
	i = 0;
	while (cpy[i] != NULL)
		++i;
	return (i);
}
