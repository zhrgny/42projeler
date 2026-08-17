/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 12:42:26 by zguney            #+#    #+#             */
/*   Updated: 2026/08/12 14:04:28 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *str;
	unsigned char *s;
	size_t i;
	
	str = dest;
	s = src;
	i = 0;

	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	return (dest);
}