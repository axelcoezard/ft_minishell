/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoezard <acoezard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:10:31 by acoezard          #+#    #+#             */
/*   Updated: 2021/11/17 17:28:44 by acoezard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *) s;
	i = 0;
	while (str[i] != (unsigned char) c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}

int	ft_strisonly(const char *s, char c)
{
	while (*s)
		if (*s++ != c)
			return (0);
	return (1);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
