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

static void		parsef(t_string *out, char *format, va_list *ap)
{
	int				i;

	ft_stringext(out, ft_strlen(format));
	i = -1;
	while (++i >= 0)
	{
		if (format[i] == '%' || format[i] == '{' || format[i] == '\0')
		{
			if (format[i] == '\0')
				break ;
			else if (format[i] == '%')
				i += parse_format(out, format + i + 1, ap);
			else if (format[i] == '{')
				i += parse_meta(out, format + i + 1);
		}
		else
			ft_stringaddc(out, format[i]);
	}
}

t_string		*ft_stringf(const char *format, ...)
{
	t_string		*str;
	va_list			ap;

	str = ft_stringnew();
	va_start(ap, format);
	parsef(str, (char*)format, &ap);
	va_end(ap);
	return (str);
}

int				ft_printf(const char *format, ...)
{
	t_string		output;
	va_list			ap;

	ft_stringini(&output);
	va_start(ap, format);
	parsef(&output, (char*)format, &ap);
	ft_stringput(&output);
	va_end(ap);
	free(output.content);
	return (output.length);
}

int				ft_printf_fd(const int fd, const char *format, ...)
{
	t_string		output;
	va_list			ap;

	ft_stringini(&output);
	va_start(ap, format);
	parsef(&output, (char*)format, &ap);
	ft_stringputfd(&output, fd);
	va_end(ap);
	free(output.content);
	return (output.length);
}
