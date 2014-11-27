/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_dd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:53:40 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 17:53:41 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_dd(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			d;

	d = (t_long)(va_arg(*ap, signed long));
	add_long(out, d, opt);
}
