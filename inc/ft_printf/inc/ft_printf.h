/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:28:42 by julifern          #+#    #+#             */
/*   Updated: 2025/01/16 17:17:57 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
int		ft_printf_options(char c, va_list args);

int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		putnbr_base(unsigned long n, char *base);
int		ft_pointer(void *ptr);

int		ft_char(int i);
int		ft_string(char *c);
int		ft_hex(va_list args, char c);
int		ft_hex_pointer(va_list args);
int		ft_int(int i, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
