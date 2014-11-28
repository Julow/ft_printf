/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_oo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:07:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 18:07:16 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_oo(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			o;
	char			*octal;

	o = (t_long)((unsigned int)(va_arg(*ap, long int)));
	octal = itobase(o, "01234567");
	add_string(out, octal, ft_strlen(octal), opt);
	free(octal);
}
