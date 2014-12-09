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
	if (opt->format->name == 'D')
		add_long(out, (t_long)(va_arg(*ap, long int)), opt);
	else
		add_long(out, get_arg(opt, ap), opt);
}
