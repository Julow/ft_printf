/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 16:06:18 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/06 12:30:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void			flag_p(t_string *out, t_opt *opt, va_list *ap)
{
	char			*hex;
	t_string		tmp;

	ft_stringini(&tmp);
	ft_stringadd(&tmp, "0x");
	if (!opt->preci_set || opt->preci != 0)
	{
		hex = ft_itobase((t_ulong)(va_arg(*ap, void*)), "0123456789abcdef");
		ft_stringadd(&tmp, hex);
		free(hex);
	}
	add_string(out, tmp.content, tmp.length, opt);
	free(tmp.content);
}
