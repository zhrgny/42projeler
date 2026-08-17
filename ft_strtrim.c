/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 16:02:51 by zguney            #+#    #+#             */
/*   Updated: 2026/08/17 12:23:39 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	end = ft_strlen(s1);
	start = 0;

	if (!s1)
		return (NULL);
	while (start <= end && ft_strchr(s1, set[start]))
		start++;
	while (start < end && ft_strchr(s1, set[end]))
		end--;
	return (ft_substr(s1, start, end - start));
}