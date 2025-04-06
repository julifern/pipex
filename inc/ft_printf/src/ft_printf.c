/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 11:12:33 by julifern          #+#    #+#             */
/*   Updated: 2025/01/16 17:20:00 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_options(char c, va_list args)
{
	int	res;

	res = 0;
	if (c == '%')
	{
		write(1, "%", 1);
		res++;
	}
	else if (c == 'c')
		res += ft_char(va_arg(args, int));
	else if (c == 's')
		res += ft_string(va_arg(args, char *));
	else if (c == 'd' || c == 'i' || c == 'u')
		res += ft_int(va_arg(args, int), c);
	else if (c == 'x' || c == 'X')
		res += ft_hex(args, c);
	else if (c == 'p')
		res += ft_hex_pointer(args);
	return (res);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			res;
	va_list		args;

	if (!s)
		return (-1);
	va_start(args, s);
	i = 0;
	res = 0;
	while (s[i] != 0)
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
			res += ft_printf_options(s[++i], args);
		else
		{
			write(1, &s[i], 1);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
