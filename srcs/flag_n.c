/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 15:52:17 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/26 15:52:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <inttypes.h>

void			flag_n(t_string *out, t_opt *opt, va_list *ap)
{
	int				*n;

	if (ft_strequ(opt->length, "hh"))
		n = (int*)(signed char*)(va_arg(*ap, int*));
	else if (ft_strequ(opt->length, "h"))
		n = (int*)(short*)(va_arg(*ap, int*));
	else if (ft_strequ(opt->length, "ll"))
		n = (int*)(va_arg(*ap, unsigned long long*));
	else if (ft_strequ(opt->length, "l"))
		n = (int*)(va_arg(*ap, unsigned long*));
	else if (ft_strequ(opt->length, "j"))
		n = (int*)(va_arg(*ap, uintmax_t*));
	else if (ft_strequ(opt->length, "t"))
		n = (int*)(va_arg(*ap, ptrdiff_t*));
	else if (ft_strequ(opt->length, "z"))
		n = (int*)(va_arg(*ap, size_t*));
	else if (ft_strequ(opt->length, "q"))
		n = (int*)(va_arg(*ap, u_quad_t*));
	else
		n = (int*)(va_arg(*ap, unsigned int*));
	*n = out->length;
}
