/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 16:24:17 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/07 11:04:36 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int		add_long(char *str, int i, t_long nb, t_opt *opt)
{
	const int		len = i;

	while (i > 0 && nb != 0)
	{
		str[i--] = '0' + ((nb < 0) ? -(nb % 10) : nb % 10);
		if (((len - i + 1) % 4) == 0 && HASF('\''))
			str[i--] = ' ';
		nb /= 10;
	}
	return (i);
}

void			flag_d(t_string *out, t_opt *opt, va_list *ap)
{
	const int		len = MAX(LONG_BUFF, MAX(opt->width, opt->preci));
	char			str[len];
	int				i;
	t_long			nb;
	t_bool			negative;

	nb = (opt->format->name == 'D') ? (t_long)(va_arg(*ap, long int)) :
		get_arg(opt, ap);
	negative = (nb < 0 || HASF('+') || HASF(' ')) ? TRUE : FALSE;
	i = len - 1;
	if (nb == 0 && (!opt->preci_set || opt->preci != 0))
		str[i--] = '0';
	else
		i = add_long(str, i, nb, opt);
	if (HASF('0') && !HASF('-') && opt->width > 0)
		while ((len - i - 1) < (negative ? opt->width - 1 : opt->width))
			str[i--] = '0';
	else if (opt->preci_set && opt->preci > 0)
		while ((len - i - 1) < opt->preci)
			str[i--] = '0';
	if (nb < 0 || HASF('+'))
		str[i--] = (nb < 0) ? '-' : '+';
	else if (HASF(' '))
		str[i--] = ' ';
	add_string(out, str + 1 + i, len - 1 - i, opt);
}
