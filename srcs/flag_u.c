/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:09:04 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 18:09:05 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void		add_ulong(t_string *out, t_ulong add, t_opt *opt)
{
	int				i;
	char			str[LONG_BUFF];

	i = LONG_BUFF;
	if (add == 0)
		str[--i] = '0';
	while (i-- > 0 && add != 0)
	{
		str[i] = '0' + add % 10;
		if (((LONG_BUFF - i + 1) % 4) == 0 && HASF('\''))
			str[--i] = ' ';
		add /= 10;
	}
	add_string(out, str + i + 1, LONG_BUFF - i - 1, opt);
}

void			flag_u(t_string *out, t_opt *opt, va_list *ap)
{
	t_ulong			u;

	if (opt->format->name == 'U')
		u = (t_ulong)(va_arg(*ap, unsigned long));
	else
		u = get_unsigned_arg(opt, ap);
	add_ulong(out, u, opt);
}
