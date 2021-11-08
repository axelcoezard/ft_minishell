/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:13:16 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/08 12:16:50 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_malloc_splits(char ***splits, const char *s, char c)
{
	int	size;
	int	i;

	size = 1;
	i = -1;
	while (s[++i])
		if (s[i] != c && size++)
			while (s[i + 1] && s[i + 1] != c)
				i++;
	*splits = malloc(size * sizeof(char *));
	return (*splits == NULL);
}

int	ft_free_splits(char **splits)
{
	while (*splits)
		free(*splits++);
	free(splits);
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char			**out;
	unsigned int	size;
	unsigned int	n;

	if (ft_malloc_splits(&out, s, c))
		return (NULL);
	n = 0;
	while (*s)
	{
		if (*s++ != c)
		{
			size = 1;
			while (*s && *s != c && size++)
				s++;
			out[n] = malloc(size + 1);
			if (out[n] == NULL && ft_free_splits(out))
				return (NULL);
			ft_strlcpy(out[n++], s - size, size + 1);
		}
	}
	out[n] = NULL;
	return (out);
}
