/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:37:58 by zguney            #+#    #+#             */
/*   Updated: 2026/09/10 18:21:43 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*s12;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s12 = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s12)
		return (NULL);
	ft_strlcpy(s12, s1, s1len + 1);
	ft_strlcat(s12, s2, s1len + s2len + 1);
	return (s12);
}
