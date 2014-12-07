/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:13:37 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 18:13:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_cc(t_string *out, t_opt *opt, va_list *ap)
{
	char			c;

	c = (char)va_arg(*ap, wint_t);
	add_string(out, &c, 1, opt);
}
