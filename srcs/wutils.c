/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/02 18:37:54 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_uint			ft_wstrlen(wchar_t *wstr)
{
	t_uint			i;

	if (wstr == NULL)
		return (0);
	i = 0;
	while (wstr[i] != '\0')
		i++;
	return (i);
}

void			compress_wstr(char *dst, wchar_t *src)
{
	while (*src != '\0')
	{
		*((t_byte*)dst) = *((t_byte*)src);
		src++;
		dst++;
	}
	*dst = '\0';
}
