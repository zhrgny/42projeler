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

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_words(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(arr[i++]);
	free(arr);
}

static size_t	get_word_end(char const *s, char c, size_t i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	fill_words(char **result, char const *s, char c)
{
	size_t	i;
	size_t	idx;
	size_t	start;

	i = 0;
	idx = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			i = get_word_end(s, c, i);
			result[idx] = ft_substr(s, start, i - start);
			if (!result[idx])
				return (free_words(result, idx), 0);
			idx++;
		}
	}
	result[idx] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	if (!fill_words(result, s, c))
		return (NULL);
	return (result);
}
