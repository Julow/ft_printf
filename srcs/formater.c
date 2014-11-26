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

char			*g_lengths[] = {
	"hh", "h", "ll", "l", "j", "z"
};

/*
** %[parameter$][flags:#, ,0,-,+][width][.precision][length:hh,h,ll,l,j,z]format
** %(?:([0-9]+)$)?([# 0-+*$L’]*)([0-9]+)?(?:\.[0-9]+)?(hh|h|ll|l|j|z)?[sSpdDioOuUxXcCeEfFgGaAn]
*/
static int		parse_flags(t_opt *opt, char *format)
{
	int				i;

	i = 0;
	while (format[i] == '#' || format[i] == ' ' || format[i] == '0'
		|| format[i] == '-' || format[i] == '+')
		i++;
	opt->flags = ft_strsub(format, 0, i);
	return (i);
}

static int		parse_width(t_opt *opt, char *format)
{
	int				length;

	length = 0;
	while (ft_isdigit(format[length]))
		length++;
	opt->width = ft_atoin(format, length);
	return (length);
}

static int		parse_precision(t_opt *opt, char *format)
{
	int				length;

	opt->precision = 0;
	if (*format != '.')
		return (0);
	format++;
	length = 0;
	while (ft_isdigit(format[length]))
		length++;
	opt->precision = ft_atoin(format, length);
	return (length);
}

static int		parse_length(t_opt *opt, char *format)
{
	int				i;

	i = -1;
	while (++i < LENGTH)
	{
		if (ft_strnequ(g_lengths[i], format, ft_strlen(g_lengths[i])))
		{
			opt->length = g_lengths[i];
			return (ft_strlen(g_lengths[i]));
		}
	}
	return (0);
}

static int		parse_format(t_string *out, char *format, va_list *ap)
{
	int				length;
	int				i;
	t_opt			*opt;

	if (*format == '%')
		return (1);
	opt = (t_opt*)malloc(sizeof(t_opt));
	length = 0;
	length += parse_flags(opt, format + length);
	length += parse_width(opt, format + length);
	length += parse_precision(opt, format + length);
	length += parse_length(opt, format + length);
	i = -1;
	while (++i < FORMATS)
	{
		if (g_formats[i].name == format[length])
			opt->format = g_formats[i];
	}
	opt->format.func(out, ap);
	free(opt->flags);
	free(opt);
	return (length);
}

static int		parse_meta(t_string *out, char *format, va_list *ap)
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
			return (length + 2);
		}
	}
	return (0);
}

int				formater(t_string *out, char *format, va_list *ap)
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
			tmp = i;
			if (format[i] == '\0')
				break ;
			else if (format[i] == '%')
				i += parse_format(out, format + i + 1, ap);
			else if (format[i] == '{')
				i += parse_meta(out, format + i + 1, ap);
			if (i < tmp)
				return (-1);
			tmp = i;
		}
	}
	return (0);
}
