/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:11:08 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 13:11:09 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <wchar.h>

void			flag_s(t_string *out, t_opt *opt, va_list *ap)
{
	char			*str;
	int				length;

	if (opt->format->name == 'S' || ft_strequ(opt->length, "l"))
		str = (char*)va_arg(*ap, wchar_t*);
	else
		str = va_arg(*ap, char*);
	if (str == NULL)
	{
		add_string(out, "(null)", 6, opt);
		return ;
	}
	length = ft_strlen(str);
	if (opt->preci >= 0 && length > opt->preci)
		length = opt->preci;
	add_string(out, ft_strdup(str), length, opt);
}
