/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:16:54 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 18:16:55 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_xx(t_string *out, t_opt *opt, va_list *ap)
{
	char			*hex;
	t_long			x;
	t_string		*tmp;

	x = get_unsigned_arg(opt, ap);
	hex = ft_itobase(x, "0123456789ABCDEF");
	if (ft_strchr(opt->flags, '#') && x > 0)
	{
		tmp = ft_stringnews("0X");
		ft_stringadd(tmp, hex);
		add_string(out, tmp->content, tmp->length, opt);
		ft_stringkil(tmp);
	}
	else
		add_string(out, hex, ft_strlen(hex), opt);
	free(hex);
}
