/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:16:05 by zguney            #+#    #+#             */
/*   Updated: 2026/08/13 19:02:26 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t 	i;
	size_t	j;

	i = 0;
	if (!little[i])
		return (char *)(&big[i]);
	while (i < len)
	{
		j = 0;
		while ((big[i] == little[j]) && (i < len))
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char *)(&big[i - j]));
		}
		i = i - j + 1;
	}
	return (NULL);
}


int	main(void)
{
	const char *big = "ababaaabaaa";
	const char *little = "abaaa";

	printf("%s", ft_strnstr(big,little,10));

}