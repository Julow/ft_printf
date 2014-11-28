/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_uu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:11:52 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 18:11:53 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_uu(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			d;

	d = (t_long)(va_arg(*ap, unsigned long));
	add_long(out, d, opt);
}
