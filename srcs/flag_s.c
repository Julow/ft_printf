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

void			flag_s(t_string *out, t_opt *opt, va_list *ap)
{
	char			*str;
	int				length;

	if (opt->format->name == 'S')
		str = (char*)va_arg(*ap, wchar_t*);
	else if (ft_strnequ(opt->length, "l", 1))
		str = (char*)va_arg(*ap, wchar_t*);
	else
		str = va_arg(*ap, char*);
	if (str == NULL)
		str = "(null)";
	length = -1;
	while (str[++length] != '\0')
		if (!ft_isprint(str[length]))
			str[length] = '?';
	if (opt->precision >= 0 && length > opt->precision)
		length = opt->precision;
	add_string(out, str, length, opt);
}
