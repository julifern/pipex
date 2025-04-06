/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:01:18 by julifern          #+#    #+#             */
/*   Updated: 2024/11/07 12:37:45 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	i;

	if ((unsigned long long) nmemb * size > 4294967295)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		s = malloc(0);
		if (!s)
			return (NULL);
		return (s);
	}
	if ((long) nmemb < 0 || (long) size < 0)
		return (NULL);
	i = size * nmemb;
	s = malloc(i);
	if (!s)
		return (NULL);
	ft_bzero(s, i);
	return (s);
}
