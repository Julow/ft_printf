/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_ss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:28:51 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 17:28:52 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_ss(t_string *out, t_opt *opt, va_list *ap)
{
	char			*str;
	int				length;

	str = (char*)va_arg(*ap, wchar_t*);
	if (str == NULL)
		str = "(null)";
	length = -1;
	while (str[++length] != '\0')
		if (str[length] < 0)
			str[length] = '?';
	add_string(out, str, length, opt);
}
