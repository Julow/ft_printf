/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:09:04 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/06 13:32:37 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int		add_ulong(char *str, int i, t_ulong nb, t_opt *opt)
{
	const int		len = i;

	while (i > 0 && nb != 0)
	{
		str[i--] = '0' + (nb % 10);
		if (((len - i + 1) % 4) == 0 && HASF('\''))
			str[i--] = ' ';
		nb /= 10;
	}
	return (i);
}

void			flag_u(t_string *out, t_opt *opt, va_list *ap)
{
	const int		len = MAX(LONG_BUFF, MAX(opt->width, opt->preci));
	char			str[len];
	int				i;
	t_long			nb;

	nb = (opt->format->name == 'U') ? (t_ulong)(va_arg(*ap, unsigned long)) :
		get_unsigned_arg(opt, ap);
	i = len - 1;
	if (nb == 0 && (!opt->preci_set || opt->preci != 0))
		str[i--] = '0';
	else
		i = add_ulong(str, i, nb, opt);
	if (HASF('0') && !HASF('-') && opt->width > 0)
		while ((len - i - 1) < ((nb < 0) ? opt->width - 1 : opt->width))
			str[i--] = '0';
	else if (opt->preci_set && opt->preci > 0)
		while ((len - i - 1) < opt->preci)
			str[i--] = '0';
	add_string(out, str + 1 + i, len - 1 - i, opt);
}
