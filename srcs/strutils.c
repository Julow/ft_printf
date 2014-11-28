/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 14:43:36 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 14:43:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char			*ft_strsub(char const *s, int start, int len)
{
	int				i;
	char			*str;

	if (s == NULL || ft_strlen(s) < start)
		return (NULL);
	str = (char*)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int				ft_strlen(const char *str)
{
	char			*tmp;

	tmp = (char*)str;
	while (*tmp != '\0')
		tmp++;
	return (tmp - str);
}

int				ft_strnequ(char const *s1, char const *s2, int n)
{
	int				i;

	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? 1 : 0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i >= n)
		i = n - 1;
	return ((s1[i] == s2[i]) ? 1 : 0);
}

char			*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			search;

	search = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == search)
			return (i + (char*)s);
		i++;
	}
	if (search == '\0')
		return (i + (char*)s);
	return (NULL);
}

char			*ft_strdup(const char *src)
{
	size_t			i;
	size_t			len;
	char			*dst;

	len = ft_strlen(src);
	dst = (char*)malloc(sizeof(char*) * (len + 1));
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
