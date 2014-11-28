/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:13:26 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 18:13:27 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_x(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			x;
	char			*hex;

	if (ft_strnequ(opt->length, "hh", 2))
		x = (t_long)(va_arg(*ap, int));
	else if (ft_strnequ(opt->length, "h", 1))
		x = (t_long)(va_arg(*ap, int));
	else if (ft_strnequ(opt->length, "ll", 2))
		x = (t_long)(va_arg(*ap, unsigned long long));
	else if (ft_strnequ(opt->length, "l", 1))
		x = (t_long)(va_arg(*ap, unsigned long));
	else if (ft_strnequ(opt->length, "j", 1))
		x = (t_long)(va_arg(*ap, uintmax_t));
	else if (ft_strnequ(opt->length, "t", 1))
		x = (t_long)(va_arg(*ap, ptrdiff_t));
	else if (ft_strnequ(opt->length, "z", 1))
		x = (t_long)(va_arg(*ap, size_t));
	else
		x = (t_long)(va_arg(*ap, unsigned int));
	hex = ft_itobase(x, "0123456789abcdef");
	add_string(out, hex, ft_strlen(hex), opt);
	free(hex);
}
