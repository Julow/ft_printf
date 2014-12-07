/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:34:31 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/26 13:34:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
** parsef
** =============
** Format 'format' using the va_list 'ap'.
** A format sequence be like:
**    %[flags][width][.precision]format
** flags can be 0 or more: '#', ' ', '-', '+', '^', '0', '''
** width is a positive integer
** precision is a positive integer or '*', precision start with '.'
** format can be one of "%sSdDoOuUxXicCnp"
** The result is added to the t_string 'out'.
** =============
** Return FALSE if an error occur or TRUE else.
** =
** =
** ft_printf
** =============
** Like parsef but the result is printed to stdout
** Nothing is printed if parsef return -1
** =============
** Return the total of char printed.
** =
** =
** ft_printf_fd
** =============
** Like ft_printf but the result is printed to the fd 'fd'
** =============
** Return the total of char printed.
*/
static t_bool	parsef(t_string *out, char *format, va_list *ap)
{
	int				i;
	int				tmp;

	ft_stringext(out, ft_strlen(format));
	i = -1;
	tmp = 0;
	while (++i >= 0)
	{
		if (format[i] == '%' || format[i] == '{' || format[i] == '\0')
		{
			tmp = i;
			if (format[i] == '\0')
				break ;
			else if (format[i] == '%')
				i += parse_format(out, format + i + 1, ap);
			else if (format[i] == '{')
				i += parse_meta(out, format + i + 1);
			if (i < tmp)
				return (FALSE);
			tmp = i;
		}
		ft_stringaddc(out, format[i]);
	}
	return (TRUE);
}

int				ft_printf(const char *format, ...)
{
	t_string		*output;
	va_list			ap;
	int				tmp;

	output = ft_stringnew();
	va_start(ap, format);
	tmp = -1;
	if (parsef(output, (char*)format, &ap))
	{
		ft_stringput(output);
		tmp = output->length;
	}
	va_end(ap);
	ft_stringkil(output);
	return (tmp);
}

int				ft_printf_fd(const int fd, const char *format, ...)
{
	t_string		*output;
	va_list			ap;
	int				tmp;

	output = ft_stringnew();
	va_start(ap, format);
	tmp = -1;
	if (parsef(output, (char*)format, &ap))
	{
		ft_stringputfd(output, fd);
		tmp = output->length;
	}
	va_end(ap);
	ft_stringkil(output);
	return (tmp);
}
