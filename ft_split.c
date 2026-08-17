/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zguney <zguney@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 12:26:49 by zguney            #+#    #+#             */
/*   Updated: 2026/08/17 14:52:04 by zguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words(char const *s, char c)
{
	size_t	i;
	size_t	words;


	i = 0;
	words = 0;
	while (s[i])
	{
		if ((s[i] != c) && (i == 0 || (s[i - 1] == c)))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	index;
	size_t	start;
	size_t	i;

	result = malloc(sizeof(char *) * (words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && (s[i] != c))
				i++;
			result[index] = ft_substr(s, start, i - start);
			index++;
		}
	}
	result[index] = NULL;
	return (result);
}

int main(void)
{
	char const *s = "zehra   güney 42 ";
	char c = ' ';
	char **result;

	printf("%zu", words(s, c));
	result = ft_split(s, c);
	printf("%s", result[1]);
}