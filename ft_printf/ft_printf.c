/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zehra <zehra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 23:50:48 by zehra             #+#    #+#             */
/*   Updated: 2026/09/26 00:51:55 by zehra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char t, va_list *args)
{
	if (t == 'c')
		return (ft_putchar((char)va_arg(*args, int)));
	if (t == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (t == 'p')
		return (ft_putptr((unsigned long)va_arg(*args, void *)));
	if (t == 'd' || t == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (t == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	if (t == 'x')
		return (ft_puthex((unsigned int)va_arg(*args, unsigned int),
				"0123456789abcdef"));
	if (t == 'X')
		return (ft_puthex((unsigned int)va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	if (t == '%')
		return (ft_putchar('%'));
	return (ft_putchar('%') + ft_putchar(t));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += ft_check_format(format[i], &args);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
