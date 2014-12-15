/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:11:25 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/09 17:11:25 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_e(t_string *out, t_opt *opt, va_list *ap)
{
	long double		e;
	t_string		str;

	e = get_float_arg(opt, ap);
	ft_stringini(&str);
	stringaddde(&str, e, (opt->preci < 0) ? 6 : opt->preci, opt);
	add_string(out, str.content, str.length, opt);
	free(str.content);
}
