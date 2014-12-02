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
	t_string		*tmp;

	o = (t_long)((unsigned int)(va_arg(*ap, long int)));
	octal = ft_itobase(o, "01234567");
	if (ft_strchr(opt->flags, '#') && o > 0)
	{
		tmp = ft_stringnews("0");
		ft_stringadd(tmp, octal);
		add_string(out, tmp->content, tmp->length, opt);
		ft_stringkil(tmp);
	}
	else
		add_string(out, octal, ft_strlen(octal), opt);
	free(octal);
}
