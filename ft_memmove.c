/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 13:11:10 by zguney            #+#    #+#             */
/*   Updated: 2026/08/12 14:04:34 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char *g;
	size_t i = 0;

	d = dest;
	s = src;
	
	while (i < n)
	{
		g[i] = s[i];
		i++;
	}
	d = g;
	return (dest);
}
