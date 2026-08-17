/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:43:16 by zguney            #+#    #+#             */
/*   Updated: 2026/08/12 16:59:50 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	int i;
	char *str;

	i = 0;
	str = s;
	while (i < n)
	{
		if (str[i] == (char)c)
		{
			return ((char *)(&str[i]));
			i++;
		}
		i++;
	}
	return (NULL);
}
