/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:13:14 by julifern          #+#    #+#             */
/*   Updated: 2025/01/16 17:18:42 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int i)
{
	return (write(1, &i, 1));
}

int	ft_string(char *c)
{
	int	res;
	int	i;

	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	res = 0;
	i = 0;
	while (c[i])
	{
		res += write(1, &c[i], 1);
		i++;
	}
	return (res);
}

int	ft_hex(va_list args, char c)
{
	unsigned int	n;
	int				res;

	res = 0;
	n = va_arg(args, unsigned int);
	if (c == 'x')
		res += putnbr_base(n, "0123456789abcdef");
	else if (c == 'X')
		res += putnbr_base(n, "0123456789ABCDEF");
	return (res);
}

int	ft_hex_pointer(va_list args)
{
	unsigned long	n;
	int				res;

	n = va_arg(args, unsigned long);
	res = ft_pointer((void *)n);
	return (res);
}

int	ft_int(int i, char c)
{
	int		res;

	res = 0;
	if (c == 'u')
	{
		i = (unsigned int)i;
		res += ft_putnbr_u(i);
	}
	else
		res += ft_putnbr(i);
	return (res);
}
