/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsalwa <dsalwa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:41:44 by dsalwa            #+#    #+#             */
/*   Updated: 2025/12/02 22:06:21 by dsalwa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (!s)
		return (0);
	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strdup(const char *s)
{
	size_t	bites;
	size_t	index;
	char	*copy;

	bites = 0;
	index = 0;
	while (s[bites])
		bites++;
	copy = malloc(bites + 1);
	if (!copy)
		return (NULL);
	while (*s != '\0')
	{
		copy[index] = *s;
		index++;
		s++;
	}
	copy[index] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		str[i++] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[i++] = *s2;
		s2++;
	}
	return (str[i] = '\0', str);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ch;

	ch = (unsigned char *)s;
	while (n--)
	{
		*ch = (unsigned char)c;
		ch++;
	}
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}
