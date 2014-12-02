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
#include <unistd.h>

static int		ft_stringf(t_string *out, char *format, va_list *ap)
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
			ft_stringaddl(out, format + tmp, i - tmp);
			tmp = i;
			if (format[i] == '\0')
				break ;
			else if (format[i] == '%')
				i += parse_format(out, format + i + 1, ap);
			else if (format[i] == '{')
				i += parse_meta(out, format + i + 1);
			if (i < tmp)
				return (-1);
			tmp = i;
		}
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	t_string		*output;
	va_list			ap;
	int				tmp;

	output = ft_stringnew();
	va_start(ap, format);
	tmp = -1;
	if (ft_stringf(output, (char*)format, &ap) >= 0)
	{
		write(1, output->content, output->length);
		tmp = output->length;
	}
	va_end(ap);
	free(output->content);
	free(output);
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
	if (ft_stringf(output, (char*)format, &ap) >= 0)
	{
		write(fd, output->content, output->length);
		tmp = output->length;
	}
	va_end(ap);
	free(output->content);
	free(output);
	return (tmp);
}
