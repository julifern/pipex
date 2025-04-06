/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:40:11 by julifern          #+#    #+#             */
/*   Updated: 2025/01/29 10:43:33 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_s1_s2(char const *s1, char const *s2, short fs1, short fs2)
{
	if (fs1)
		free((void *)s1);
	if (fs2)
		free((void *)s2);
}

char	*ft_strjoin_free(char const *s1, char const *s2, short fs1, short fs2)
{
	char		*joined;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	joined = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!joined)
		return (NULL);
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joined[i] = s2[j++];
		i++;
	}
	joined[i] = '\0';
	free_s1_s2(s1, s2, fs1, fs2);
	return (joined);
}
