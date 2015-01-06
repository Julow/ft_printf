/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 13:11:08 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/06 14:12:11 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void		flag_ws(t_string *out, t_opt *opt, wchar_t *wstr)
{
	const int		len = ft_wstrlen(wstr);
	char			str[len + 1];
	int				length;

	length = len;
	if (wstr == NULL)
	{
		add_string(out, "(null)", 6, opt);
		return ;
	}
	compress_wstr(str, wstr);
	if (opt->preci_set && length > opt->preci)
		length = opt->preci;
	if (opt->preci_set && opt->preci < 0)
		add_nchar(out, ' ', ABS(length), opt);
	else
		add_string(out, str, length, opt);
}

void			flag_s(t_string *out, t_opt *opt, va_list *ap)
{
	char			*str;
	int				length;

	if (opt->format->name == 'S' || ft_strequ(opt->length, "l"))
	{
		flag_ws(out, opt, va_arg(*ap, wchar_t*));
		return ;
	}
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
