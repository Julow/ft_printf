/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:47:13 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/26 19:47:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <sys/types.h>

char			add_string(t_string *out, char *add, int len, t_opt *opt)
{
	char			*left;

	left = ft_strchr(opt->flags, '-');
	if (left == NULL && !ft_stringaddl(out, add, len))
		return (0);
	ft_stringaddcn(out, (ft_strchr(opt->flags, '0') == NULL) ? ' ' : '0',
		opt->width - len);
	if (left != NULL && !ft_stringaddl(out, add, len))
		return (0);
	return (1);
}

char			add_long(t_string *out, t_long add, t_opt *opt)
{
	int				i;
	int				length;
	t_long			tmp;
	char			str[21];

	tmp = add;
	length = (tmp < 0 || ft_strchr(opt->flags, ' ')
		|| ft_strchr(opt->flags, '+')) ? 2 : 1;
	while ((tmp /= 10) != 0)
		length++;
	i = length;
	tmp = add;
	while (i-- > 0)
	{
		str[i] = '0' + ((add < 0) ? -(add % 10) : add % 10);
		add /= 10;
	}
	if (tmp < 0)
		str[0] = '-';
	else if (ft_strchr(opt->flags, '+'))
		str[0] = '+';
	else if (ft_strchr(opt->flags, ' '))
		str[0] = ' ';
	return (add_string(out, str, length, opt));
}

int				ft_atoin(char *str, int len)
{
	int				nb;
	int				sign;

	sign = 1;
	nb = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
		len--;
	}
	else if (*str == '+')
	{
		len--;
		str++;
	}
	while (*str >= '0' && *str <= '9' && len > 0)
	{
		len--;
		nb = nb * 10 + (*(str++) - '0');
	}
	return (nb * sign);
}

t_long			get_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "hh"))
		return ((t_long)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "h"))
		return ((t_long)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "ll"))
		return ((t_long)(va_arg(*ap, long long)));
	if (ft_strequ(opt->length, "l"))
		return ((t_long)(va_arg(*ap, long)));
	if (ft_strequ(opt->length, "j"))
		return ((t_long)(va_arg(*ap, intmax_t)));
	if (ft_strequ(opt->length, "t"))
		return ((t_long)(va_arg(*ap, ptrdiff_t)));
	if (ft_strequ(opt->length, "z"))
		return ((t_long)(va_arg(*ap, size_t)));
	if (ft_strequ(opt->length, "q"))
		return ((t_long)(va_arg(*ap, quad_t)));
	return ((t_long)(va_arg(*ap, int)));
}

t_ulong			get_unsigned_arg(t_opt *opt, va_list *ap)
{
	if (ft_strequ(opt->length, "hh"))
		return ((t_long)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "h"))
		return ((t_long)(va_arg(*ap, int)));
	if (ft_strequ(opt->length, "ll"))
		return ((t_long)(va_arg(*ap, unsigned long long)));
	if (ft_strequ(opt->length, "l"))
		return ((t_long)(va_arg(*ap, unsigned long)));
	if (ft_strequ(opt->length, "j"))
		return ((t_long)(va_arg(*ap, uintmax_t)));
	if (ft_strequ(opt->length, "t"))
		return ((t_long)(va_arg(*ap, ptrdiff_t)));
	if (ft_strequ(opt->length, "z"))
		return ((t_long)(va_arg(*ap, size_t)));
	if (ft_strequ(opt->length, "q"))
		return ((t_long)(va_arg(*ap, u_quad_t)));
	return ((t_long)(va_arg(*ap, unsigned int)));
}
