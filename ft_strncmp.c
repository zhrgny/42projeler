/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:38:53 by zguney            #+#    #+#             */
/*   Updated: 2026/08/12 17:11:51 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;
	
	i = 0;
	while ((s1[i]) && (s2[i]) && (i < n))
	{
		if ((s1[i]) != (s2[i]))
			return((s1[i]) - (s2[i]));
		i++;
	}
	if (i < n)
		return((s1[i]) - (s2[i]));
	return(0);
}