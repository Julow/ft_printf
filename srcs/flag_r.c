/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:53:49 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/09 17:53:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void		stringaddcr(t_string *str, char r)
{
	if (!ft_isprint(r))
	{
		ft_stringaddc(str, '\\');
		ft_stringaddi(str, r);
	}
	else
		ft_stringaddc(str, r);
}

void			flag_r(t_string *out, t_opt *opt, va_list *ap)
{
	char			*r;
	t_string		str;
	int				length;

	if (opt->format->name == 'R')
		r = (char*)va_arg(*ap, wchar_t*);
	else if (ft_strequ(opt->length, "l"))
		r = (char*)va_arg(*ap, wchar_t*);
	else
		r = va_arg(*ap, char*);
	if (r == NULL)
	{
		add_string(out, "(null)", 6, opt);
		return ;
	}
	ft_stringini(&str);
	ft_stringext(&str, ft_strlen(r));
	length = -1;
	while (r[++length] != '\0')
		stringaddcr(&str, r[length]);
	if (opt->preci >= 0 && length > opt->preci)
		length = opt->preci;
	add_string(out, str.content, length, opt);
	free(str.content);
}
