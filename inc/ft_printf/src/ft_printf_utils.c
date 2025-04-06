/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:13:10 by julifern          #+#    #+#             */
/*   Updated: 2025/01/16 17:14:28 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr_u(n / 10);
		i += ft_putnbr_u(n % 10);
	}
	else
		i += ft_char(n + '0');
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		i += write (1, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_char(n + '0');
	return (i);
}

int	putnbr_base(unsigned long n, char *base)
{
	char			c;
	unsigned long	len;

	len = ft_strlen(base);
	if (n >= len)
		return (putnbr_base(n / len, base) + putnbr_base(n % len, base));
	else
	{
		c = base[n];
		write(1, &c, 1);
		return (1);
	}
}

int	ft_pointer(void *ptr)
{
	unsigned long	i;
	int				res;

	i = (unsigned long)ptr;
	res = 0;
	if (i == 0)
	{
		res += write(1, "(nil)", 5);
		return (res);
	}
	else
	{
		res += write(1, "0x", 2);
		res += putnbr_base(i, "0123456789abcdef");
	}
	return (res);
}
