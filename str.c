/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberger- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:37:31 by mberger-          #+#    #+#             */
/*   Updated: 2021/11/12 09:08:20 by mberger-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != 0)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (--size && *src && ++i)
		*dst++ = *src++;
	*dst = '\0';
	while (*src++)
		i++;
	return (i);
}

int	ft_strisonly(const char *s, char c)
{
	while (*s)
		if (*s++ != c)
			return (0);
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
		if (*s1++ != *s2++)
			return (*(unsigned char *)--s1 - *(unsigned char *)--s2);
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*s;
	int		len;

	len = ft_strlen(str) + 1;
	s = malloc(len * sizeof(char));
	ft_strlcpy(s, str, len);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
		if (*s == (char)c)
			return ((char *)s);
	else if (*s++ == '\0')
		break ;
	return (NULL);
}
