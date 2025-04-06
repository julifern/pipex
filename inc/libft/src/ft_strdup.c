/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:46:48 by julifern          #+#    #+#             */
/*   Updated: 2024/11/02 18:19:12 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dst;

	i = -1;
	dst = ft_calloc(ft_strlen(s) + 1, 1);
	if (!dst)
		return (NULL);
	while (s[++i])
		dst[i] = s[i];
	return (dst);
}
