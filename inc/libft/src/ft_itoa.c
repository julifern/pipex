/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:44:49 by julifern          #+#    #+#             */
/*   Updated: 2024/11/07 12:31:54 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_decimal(int n)
{
	int	decimal;

	if (n == -2147483648)
		return (11);
	decimal = 0;
	if (n < 0)
	{
		n *= -1;
		decimal++;
	}
	while (n >= 10)
	{
		n /= 10;
		decimal++;
	}
	decimal++;
	return (decimal);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_decimal(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n >= 10)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	str[i--] = n + '0';
	return (str);
}
