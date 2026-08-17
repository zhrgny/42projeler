/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:09:34 by zguney            #+#    #+#             */
/*   Updated: 2026/08/17 14:45:11 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *a;
	size_t	s_len = ft_strlen(s);
	size_t	i;

	if (start >= s_len)
		len = 0;
	if (len > s_len - start)
		len = s_len - start;
	a = malloc (sizeof(char) * (len + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}