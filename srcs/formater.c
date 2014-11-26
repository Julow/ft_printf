/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:12:03 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/26 14:12:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** sSpdDioOuUxXcC	eE, fF, gG, aA, n
** # 0-+	*$L’
** hhhllljz
*/
t_format		g_formats[] = {
	{'n', &flag_n}
};

t_meta			g_metas[] = {
	{"cyan", "\033[1;36m"},
	{"turquoise", "\033[0;36m"},
	{"dark", "\033[1;30m"},
	{"reset", "\033[0;0m"},
	{"eoc", "\033[0m"}
};

static int		flag(t_string *out, char *format, va_list *ap)
{
	int				i;

	if (*format == '%')
		return (1);
	i = -1;
	return (0);
}

static int		meta(t_string *out, char *format, va_list *ap)
{
	int				i;
	int				length;

	length = 0;
	while (format[length] != '}' && format[length] != '\0')
		length++;
	i = -1;
	while (++i < 5)
	{
		if (ft_strnequ(format, g_metas[i].name, length))
		{
			ft_stringaddl(out, g_metas[i].value, ft_strlen(g_metas[i].value));
			return (length + 2);
		}
	}
	return (0);
}

void			formater(t_string *out, char *format, va_list *ap)
{
	int				i;
	int				tmp;

	i = -1;
	tmp = 0;
	while (++i >= 0)
	{
		if (format[i] == '%' || format[i] == '{' || format[i] == '\0')
		{
			ft_stringaddl(out, format + tmp, i - tmp);
			if (format[i] == '%')
				i += flag(out, format + i + 1, ap);
			else if (format[i] == '{')
				i += meta(out, format + i + 1, ap);
			tmp = i;
		}
		if (format[i] == '\0')
			break ;
	}
}
