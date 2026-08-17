/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:03:17 by zguney            #+#    #+#             */
/*   Updated: 2026/08/12 17:15:18 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = str1;
	s2 = str2;

	while (i < n)
	{
		if ((s1[i]) != (s2[i]))
			return ((s1[i]) - (s2[i]));
		i++;
	}

	return (0);
}
