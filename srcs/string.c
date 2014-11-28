/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:39:17 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/26 14:39:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_string		*ft_stringnew(void)
{
	t_string		*str;

	str = (t_string*)malloc(sizeof(t_string));
	if (str != NULL)
	{
		str->content = (char*)malloc(sizeof(char) * 16);
		if (str->content != NULL)
			str->content[0] = '\0';
		str->length = 0;
		str->alloc_length = (str->content == NULL) ? 0 : 16;
	}
	return (str);
}

char			ft_stringaddc(t_string *str, char c)
{
	if (!ft_stringext(str, 1))
		return (0);
	str->content[str->length] = c;
	str->length++;
	return (1);
}

char			ft_stringaddcn(t_string *str, char c, int n)
{
	if (!ft_stringext(str, n))
		return (0);
	while (n-- > 0)
	{
		str->content[str->length] = c;
		str->length++;
	}
	return (1);
}

char			ft_stringaddl(t_string *str, char *add, int len)
{
	int				i;

	if (!ft_stringext(str, len))
		return (0);
	i = -1;
	while (++i < len)
		str->content[str->length + i] = add[i];
	str->length += len;
	return (1);
}

char			ft_stringext(t_string *str, int need)
{
	char			*tmp;
	int				i;

	need += str->length;
	if (need + 1 < str->alloc_length)
		return (1);
	i = str->alloc_length - 1;
	while (need >= i)
		i += 24;
	tmp = (char*)malloc(sizeof(char) * i);
	if (tmp == NULL)
		return (0);
	str->alloc_length = i;
	i = -1;
	if (str->content != NULL)
	{
		while (++i < str->length)
			tmp[i] = str->content[i];
		i--;
		free(str->content);
	}
	while (++i < str->alloc_length)
		tmp[i] = '\0';
	str->content = tmp;
	return (1);
}
