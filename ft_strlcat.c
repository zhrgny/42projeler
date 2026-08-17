/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 16:11:48 by zguney            #+#    #+#             */
/*   Updated: 2026/08/17 14:51:19 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat ( char *dst , const char *src , size_t size )
{
	size_t	i;
	size_t j;
	
	i = 0;
	j = ft_strlen(dst);
	
	while ((src[i]) && (j < size - j - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (j);
}