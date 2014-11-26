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
#include <stdarg.h>

t_format		g_formats[] = {
	{'n', &flag_n}
};

static void		flag(t_string *out, char **flag, va_list *ap)
{
	++*flag;
}

void			formater(t_string *out, const char *format, va_list *ap)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = (char*)format;
	while (1)
	{
		if (*tmp == '%' || tmp[1] == '\0')
		{
			i = tmp - format;
			ft_stringaddl(out, format + i, )
			flag(out, &tmp, ap);
		}
	}
}
