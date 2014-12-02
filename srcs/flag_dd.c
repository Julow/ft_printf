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
	add_long(out, (t_long)((int)(va_arg(*ap, long int))), opt);
}
