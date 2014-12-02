/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 16:06:18 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/02 16:06:19 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_p(t_string *out, t_opt *opt, va_list *ap)
{
	t_ulong			p;
	char			*hex;
	t_string		*tmp;

	p = (t_ulong)(va_arg(*ap, void*));
	tmp = ft_stringnews("0x");
	hex = ft_itobase(p, "0123456789abcdef");
	ft_stringadd(tmp, hex);
	free(hex);
	add_string(out, tmp->content, tmp->length, opt);
	ft_stringkil(tmp);
}
