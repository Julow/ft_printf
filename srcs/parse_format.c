/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:29:03 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 11:29:04 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
** sSdDoOuUxXicCn
** %%
** #, ,0,-,+
** width
** precision
** hh,h,ll,l,j,t,z
** =============
** p
** =============
** *,$,L,’
** eEfFgGaA
** brk
*/
t_format		g_formats[] = {
	{'%', &flag_percent},
	{'s', &flag_s},
	{'S', &flag_ss},
	{'d', &flag_d},
	{'D', &flag_dd},
	{'o', &flag_o},
	{'O', &flag_oo},
	{'u', &flag_u},
	{'U', &flag_uu},
	{'x', &flag_x},
	{'X', &flag_xx},
	{'i', &flag_d},
	{'c', &flag_c},
	{'C', &flag_cc},
	{'n', &flag_n}
};

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
	return (length + 1);
}

static int		parse_length(t_opt *opt, char *format)
{
	int				i;
	int				len;
	const char		*lengths[] = {"hh", "h", "ll", "l", "j", "t", "z", NULL};

	i = -1;
	while (lengths[++i] != NULL)
	{
		len = ft_strlen(lengths[i]);
		if (ft_strnequ(lengths[i], format, len))
		{
			opt->length = lengths[i];
			return (len);
		}
	}
	return (0);
}

int				parse_format(t_string *out, char *format, va_list *ap)
{
	int				length;
	int				i;
	t_opt			opt;

	length = 0;
	length += parse_flags(&opt, format + length);
	length += parse_width(&opt, format + length);
	length += parse_precision(&opt, format + length);
	length += parse_length(&opt, format + length);
	i = -1;
	while (++i < FORMATS)
	{
		if (g_formats[i].name == format[length])
		{
			g_formats[i].func(out, &opt, ap);
			free(opt.flags);
			return (length + 1);
		}
	}
	free(opt.flags);
	return (0);
}
