/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:27:34 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 15:27:35 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_c(t_string *out, t_opt *opt, va_list *ap)
{
	char			c;

	if (ft_strnequ(opt->length, "l", 1))
		c = (char)va_arg(*ap, wint_t);
	else
		c = (char)va_arg(*ap, int);
	add_string(out, &c, 1, opt);
}
