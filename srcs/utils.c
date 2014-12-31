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
	char const		fill = (!HASF('0')) ? ' ' : '0';

	left = ft_strrchr(opt->flags, '-');
	center = ft_strrchr(opt->flags, '^');
	center = (center > left) ? center : NULL;
	left = (left > center) ? left : NULL;
	if ((left == NULL && opt->width > 0) || center != NULL)
		ft_stringaddcn(out, fill, ((center != NULL) ? (opt->width - len) / 2 :
			opt->width - len));
	ft_stringaddl(out, add, len);
	if (left != NULL || opt->width < 0 || center != NULL)
		ft_stringaddcn(out, fill, ((center != NULL) ? (ABS(opt->width) - len)
			/ 2 : ABS(opt->width) - len));
}

void			add_long(t_string *out, t_long add, t_opt *opt)
{
	int				i;
	t_long			tmp;
	char			str[LONG_BUFF];

	//ft_bzero(str, LONG_BUFF);
	i = LONG_BUFF;
	tmp = add;
	if (add == 0)
		str[--i] = '0';
	while (i-- > 0 && add != 0)
	{
		str[i] = '0' + ((add < 0) ? -(add % 10) : add % 10);
		if (((LONG_BUFF - i + 1) % 4) == 0 && HASF('\''))
			str[--i] = ' ';
		add /= 10;
	}
	if (tmp < 0 || HASF('+'))
		str[i--] = (tmp < 0) ? '-' : '+';
	else if (HASF(' '))
		str[i--] = ' ';
	add_string(out, str + i + 1, LONG_BUFF - i - 1, opt);
}

void			clear_dis(t_opt *opt)
{
	int				i;

	i = -1;
	while (opt->flags[++i] != '\0')
		if (ft_strchr(opt->format->disabled, opt->flags[i]))
			opt->flags[i] = ';';
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
