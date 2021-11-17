/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:38:39 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/17 15:35:56 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pipe_split_sep(char c)
{
	return (c == '|' || c == '\0');
}

static int	pipe_split_search(const char *s)
{
	int		j;

	j = 0;
	while (!pipe_split_sep(s[j]))
		j++;
	return (j);
}

static int	pipe_split_size(const char *s)
{
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (!pipe_split_sep(s[i]) && pipe_split_sep(s[i + 1]))
			size++;
		i++;
	}
	return (size);
}

static char	*pipe_split_copy(const char *s, int start, int size)
{
	char	*word;
	int		i;

	word = (char *) malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		word[i] = s[start + i];
		i++;
	}
	return (word);
}

char	**pipe_split(const char *s)
{
	char	**words;
	int		size;
	int		i;
	int		j;
	int		k;

	size = pipe_split_size(s);
	words = (char **) malloc(sizeof(char *) * (size + 1));
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '|')
			i++;
		else
		{
			j = pipe_split_search(s + i) + 1;
			words[k++] = pipe_split_copy(s, i, j);
			i += j;
		}
	}
	words[size] = NULL;
	return (words);
}
