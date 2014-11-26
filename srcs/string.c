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

#include "ft_printf.h"
#include <stdlib.h>

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
