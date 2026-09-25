/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zehra <zehra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 23:29:58 by zehra             #+#    #+#             */
/*   Updated: 2026/09/25 23:48:30 by zehra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nb, char *base)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += ft_puthex(nb / 16, base);
	len += ft_putchar(base[nb % 16]);
	return (len);
}

int	ft_putptr(unsigned long nb)
{
	int	len;

	if (nb == 0)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	len += ft_puthex(nb, "0123456789abcdef");
	return (len);
}
