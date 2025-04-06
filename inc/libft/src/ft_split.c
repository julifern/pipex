/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:41:19 by julifern          #+#    #+#             */
/*   Updated: 2024/11/07 12:31:41 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			word_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word_count);
}

static int	ft_word_len(char const *s, char c)
{
	int	i;
	int	word_len;

	i = 0;
	word_len = 0;
	while (s[i] && s[i] != c)
	{
		word_len++;
		i++;
	}
	return (word_len);
}

static char	**ft_free_tabs(char **str, int j)
{
	while (--j)
		free(str[j]);
	free(str);
	return (NULL);
}

static char	**ft_splitter(char **str, char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		len = ft_word_len(&s[i], c);
		if (len == 0)
			break ;
		str[j] = ft_substr(s, i, len);
		if (!str[j])
			return (ft_free_tabs(str, j));
		i += len;
		j++;
	}
	str[j] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		words;

	if (!s)
		return (NULL);
	words = ft_word_counter(s, c);
	str = malloc(sizeof(char *) * (words + 1));
	if (!str)
		return (NULL);
	if (words == 0)
	{
		str[0] = NULL;
		return (str);
	}
	str = ft_splitter(str, s, c);
	return (str);
}
