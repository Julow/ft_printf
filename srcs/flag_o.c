/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:54:49 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 17:54:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void			flag_o(t_string *out, t_opt *opt, va_list *ap)
{
	t_ulong			o;
	char			*octal;
	t_string		tmp;

	if (opt->format->name == 'O')
		o = (t_long)(va_arg(*ap, unsigned long long int));
	else
		o = get_unsigned_arg(opt, ap);
	octal = ft_itobase(o, "01234567");
	if (ft_strchr(opt->flags, '#') && o > 0)
	{
		ft_stringini(&tmp);
		ft_stringadd(&tmp, "0");
		ft_stringadd(&tmp, octal);
		add_string(out, tmp.content, tmp.length, opt);
		free(tmp.content);
	}
	else
		add_string(out, octal, ft_strlen(octal), opt);
	free(octal);
}
