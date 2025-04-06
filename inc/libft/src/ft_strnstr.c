/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:09:08 by julifern          #+#    #+#             */
/*   Updated: 2024/11/04 13:58:23 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;

	l_len = ft_strlen(little);
	if (!ft_strlen(little))
		return ((char *)big);
	while (*big && (--len + 1 >= l_len))
	{
		if (!ft_strncmp(big, little, l_len))
			return ((char *)big);
		big++;
	}
	return (0);
}
