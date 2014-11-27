/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:59:10 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 11:59:10 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_meta			g_metas[] = {
	{"cyan", "\033[1;36m"},
	{"turquoise", "\033[0;36m"},
	{"dark", "\033[1;30m"},
	{"reset", "\033[0;0m"},
	{"eoc", "\033[0m"}
};

int				parse_meta(t_string *out, char *format)
{
	int				i;
	int				length;

	length = 0;
	while (format[length] != '}' && format[length] != '\0')
		length++;
	i = -1;
	while (++i < METAS)
	{
		if (ft_strnequ(format, g_metas[i].name, length))
		{
			ft_stringaddl(out, g_metas[i].value, ft_strlen(g_metas[i].value));
			return (length + 1);
		}
	}
	return (0);
}
