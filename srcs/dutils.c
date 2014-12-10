/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 16:45:49 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/09 16:45:50 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			stringaddid(t_string *str, long double nbr)
{
	int				tmp;
	int				length;

	length = ((nbr < 0) ? 2 : 1);
	while ((nbr /= 10) > 1)
		length++;
	ft_stringext(str, length);
	if (nbr < 0)
		str->content[str->length++] = '-';
	length += str->length;
	while (str->length < length)
	{
		nbr *= 10;
		tmp = (int)nbr;
		str->content[str->length++] = '0' + tmp;
		nbr -= tmp;
	}
}

static void		fix_precision(t_string *str)
{
	int				i;

	i = str->length;
	while (str->content[--i] == '9')
		str->content[i] = '0';
	str->content[i]++;
}

void			stringaddd(t_string *str, long double d, int preci, t_opt *opt)
{
	int				i;
	int				tmp;

	if (d < 0 || ft_strchr(opt->flags, '+'))
		ft_stringaddc(str, (d < 0) ? '-' : '+');
	else if (ft_strchr(opt->flags, ' '))
		ft_stringaddc(str, ' ');
	stringaddid(str, (preci <= 0) ? d + 0.5 : d);
	if (preci <= 0)
		return ;
	ft_stringext(str, preci + 1);
	ft_stringaddc(str, '.');
	d -= (int)d;
	i = -1;
	while (++i < preci)
	{
		d *= 10;
		if ((i + 1) >= preci)
			d += 0.5;
		tmp = (int)d;
		if (tmp >= 10 && (tmp %= 10) >= 0)
			fix_precision(str);
		str->content[str->length++] = '0' + tmp;
		d -= tmp;
	}
}

void			stringaddde(t_string *str, long double d, int pre, t_opt *opt)
{
	int				p;

	if (d < 0)
	{
		ft_stringaddc(str, '-');
		d = -d;
	}
	p = 0;
	while (d > 10)
	{
		d /= 10;
		p++;
	}
	while (d < 1)
	{
		d *= 10;
		p--;
	}
	stringaddd(str, d, pre, opt);
	ft_stringaddc(str, opt->format->name);
	ft_stringaddc(str, (p < 0) ? '-' : '+');
	if (p > -10 && p < 10)
		ft_stringaddc(str, '0');
	ft_stringaddi(str, (p < 0) ? -p : p);
}
