/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:24:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/09 17:24:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_f(t_string *out, t_opt *opt, va_list *ap)
{
	long double		f;
	t_string		*str;

	f = get_float_arg(opt, ap);
	str = ft_stringnew();
	stringaddd(str, f, (opt->preci < 0) ? 6 : opt->preci, opt);
	add_string(out, str->content, str->length, opt);
	ft_stringkil(str);
}
