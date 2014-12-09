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

	if (opt->format->name == 'U')
		d = (t_long)(va_arg(*ap, unsigned long));
	else
		d = get_unsigned_arg(opt, ap);
	add_long(out, d, opt);
}
