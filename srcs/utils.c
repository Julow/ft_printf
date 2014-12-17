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

void			add_string(t_string *out, char *add, int len, t_opt *opt)
{
	char			*left;
	char			*center;
	char const		fill = (ft_strchr(opt->format->disabled, '0') ||

	ft_strchr(opt->flags, '0') == NULL) ? ' ' : '0';
	left = ft_strrchr(opt->flags, '-');
	center = ft_strrchr(opt->flags, '^');
	center = (center > left) ? center : NULL;
	left = (left > center) ? left : NULL;
	if (left == NULL || center != NULL)
		ft_stringaddcn(out, fill, ((center != NULL) ? (opt->width - len) / 2 :
			opt->width - len));
	ft_stringaddl(out, add, len);
	if (left != NULL || center != NULL)
		ft_stringaddcn(out, fill, ((center != NULL) ? (opt->width - len) / 2 :
			opt->width - len));
}

void			add_long(t_string *out, t_long add, t_opt *opt)
{
	int				i;
	int				length;
	t_long			tmp;
	char			str[30];

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
		if (((length - i) % 3) == 0 && ft_strchr(opt->flags, '\''))
			str[--i] = ' ';
		add /= 10;
	}
	if (tmp < 0 || ft_strchr(opt->flags, '+'))
		str[0] = (tmp < 0) ? '-' : '+';
	else if (ft_strchr(opt->flags, ' '))
		str[0] = ' ';
	add_string(out, str, length, opt);
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
	while (*str >= '0' && *str <= '9' && len-- > 0)
		nb = nb * 10 + (*(str++) - '0');
	return (nb * sign);
}
