/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:27:34 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/06 13:38:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_c(t_string *out, t_opt *opt, va_list *ap)
{
	const int		len = MAX(opt->width, 1);
	int				i;
	char			c[len];

	i = len - 1;
	if (opt->format->name == 'C' || ft_strequ(opt->length, "l"))
		c[i--] = (char)((t_uchar)((t_uint)va_arg(*ap, wint_t)));
	else
		c[i--] = (char)va_arg(*ap, int);
	if (HASF('0') && !HASF('-') && opt->width > 0)
		while ((len - i - 1) < opt->width)
			c[i--] = '0';
	add_string(out, c + 1 + i, len - 1 - i, opt);
}
