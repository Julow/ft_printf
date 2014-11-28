/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:54:49 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 17:54:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_o(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			o;
	char			*octal;

	if (ft_strnequ(opt->length, "hh", 2))
		o = (t_long)(va_arg(*ap, unsigned char));
	else if (ft_strnequ(opt->length, "h", 1))
		o = (t_long)(va_arg(*ap, unsigned short));
	else if (ft_strnequ(opt->length, "ll", 2))
		o = (t_long)(va_arg(*ap, unsigned long long));
	else if (ft_strnequ(opt->length, "l", 1))
		o = (t_long)(va_arg(*ap, unsigned long));
	else if (ft_strnequ(opt->length, "j", 1))
		o = (t_long)(va_arg(*ap, uintmax_t));
	else if (ft_strnequ(opt->length, "t", 1))
		o = (t_long)(va_arg(*ap, ptrdiff_t));
	else if (ft_strnequ(opt->length, "z", 1))
		o = (t_long)(va_arg(*ap, size_t));
	else
		o = (t_long)(va_arg(*ap, int));
	octal = itobase(o, "01234567");
	add_string(out, octal, ft_strlen(octal), opt);
	free(octal);
}
