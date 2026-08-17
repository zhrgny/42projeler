/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:30:35 by zguney            #+#    #+#             */
/*   Updated: 2026/08/12 17:01:13 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	
	i = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			i--;
			return((char *)(&s[i]));
		}
		i--;
	}
	return('\0');
}