/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:09:04 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 18:09:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_u(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			d;

	if (ft_strnequ(opt->length, "hh", 2))
		d = (t_long)(va_arg(*ap, int));
	else if (ft_strnequ(opt->length, "h", 1))
		d = (t_long)(va_arg(*ap, int));
	else if (ft_strnequ(opt->length, "ll", 2))
		d = (t_long)(va_arg(*ap, unsigned long long));
	else if (ft_strnequ(opt->length, "l", 1))
		d = (t_long)(va_arg(*ap, unsigned long));
	else if (ft_strnequ(opt->length, "j", 1))
		d = (t_long)(va_arg(*ap, uintmax_t));
	else if (ft_strnequ(opt->length, "t", 1))
		d = (t_long)(va_arg(*ap, ptrdiff_t));
	else if (ft_strnequ(opt->length, "z", 1))
		d = (t_long)(va_arg(*ap, size_t));
	else
		d = (t_long)(va_arg(*ap, unsigned int));
	add_long(out, d, opt);
}
