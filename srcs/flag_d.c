/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:24:17 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 16:24:18 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_d(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			d;

	if (ft_strnequ(opt->length, "hh", 2))
		d = (t_long)(va_arg(*ap, int));
	else if (ft_strnequ(opt->length, "h", 1))
		d = (t_long)(va_arg(*ap, int));
	else if (ft_strnequ(opt->length, "ll", 2))
		d = (t_long)(va_arg(*ap, long long));
	else if (ft_strnequ(opt->length, "l", 1))
		d = (t_long)(va_arg(*ap, long));
	else if (ft_strnequ(opt->length, "j", 1))
		d = (t_long)(va_arg(*ap, intmax_t));
	else if (ft_strnequ(opt->length, "t", 1))
		d = (t_long)(va_arg(*ap, ptrdiff_t));
	else if (ft_strnequ(opt->length, "z", 1))
		d = (t_long)(va_arg(*ap, size_t));
	else
		d = (t_long)(va_arg(*ap, int));
	add_long(out, d, opt);
}
