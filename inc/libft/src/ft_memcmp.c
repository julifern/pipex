/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:59:00 by julifern          #+#    #+#             */
/*   Updated: 2024/11/05 19:14:50 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n && *s1_tmp == *s2_tmp)
	{
		n--;
		s1_tmp++;
		s2_tmp++;
	}
	if (n)
		return (*s1_tmp - *s2_tmp);
	return (0);
}
