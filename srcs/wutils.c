/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 17:45:40 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/08 17:27:09 by jaguillo         ###   ########.fr       */
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

int				ft_strutf8(char *buff, wchar_t *wstr)
{
	int				i;
	int				len;

	len = 0;
	i = -1;
	while (wstr[++i] != 0)
		len += ft_widetoa(buff + (i * 4), wstr[i]);
	return (len + 1);
}

int				ft_strnutf8(char *buff, wchar_t *wstr, int n)
{
	int				i;
	int				len;

	len = 0;
	i = -1;
	while (wstr[++i] != 0 && (i * 4) < n)
		len += ft_widetoa(buff + (i * 4), wstr[i]);
	return (len + 1);
}

int				ft_widetoa(char *buff, wchar_t w)
{
	if (w < 0x80)
	{
		*(buff++) = (((w >> 0) & 0x7F) | 0);
		return (1);
	}
	else if (w < 0x800)
	{
		*(buff++) = ((w >> 6) & 0x1F) | 0xC0;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (2);
	}
	else if (w < 0x10000)
	{
		*(buff++) = ((w >> 12) & 0xF) | 0xE0;
		*(buff++) = ((w >> 6) & 0x1F) | 0x80;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (3);
	}
	else if (w < 0x110000)
	{
		*(buff++) = ((w >> 18) & 0x7) | 0xF0;
		*(buff++) = ((w >> 12) & 0x3F) | 0x80;
		*(buff++) = ((w >> 6) & 0x3F) | 0x80;
		*(buff++) = ((w >> 0) & 0x3F) | 0x80;
		return (4);
	}
	return (0);
}
