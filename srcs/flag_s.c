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

static void		add_nchar(t_string *out, char c, int len, t_opt *opt)
{
	char			str[len];

	ft_memset(str, c, len);
	add_string(out, str, len, opt);
}

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
	if (opt->preci_set && length > opt->preci)
		length = opt->preci;
	if (opt->preci_set && opt->preci < 0)
		add_nchar(out, ' ', ABS(length), opt);
	else
		add_string(out, str, length, opt);
}
