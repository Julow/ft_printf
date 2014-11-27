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

	str = (char*)va_arg(*ap, wchar_t*);
	add_string(out, str, ft_strlen(str), opt);
}
