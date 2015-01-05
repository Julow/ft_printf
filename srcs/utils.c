/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:47:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/05 17:38:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int		str_trans(char *dst, const char *src, int len, t_opt *opt)
{
	ft_memmove(dst, src, len);
	if (ft_strrchr(opt->flags, 'T') != NULL)
		len = ft_strtrim2(dst, len, " \t\n\r\f");
	if (ft_strrchr(opt->flags, 'M') != NULL)
		ft_strupper(dst);
	else if (ft_strrchr(opt->flags, 'm') != NULL)
		ft_strlower(dst);
	return (len);
}

void			add_string(t_string *out, const char *add, int len, t_opt *opt)
{
	char			*left;
	char			*center;
	char			*start;
	char			tmp[len];
	char const		fill = (!HASF('0')) ? ' ' : '0';

	left = ft_strrchr(opt->flags, '-');
	center = ft_strrchr(opt->flags, '^');
	start = ft_strrchr(opt->flags, '>');
	center = (center > left && center > start) ? center : NULL;
	left = (left > center && left > start) ? left : NULL;
	start = (start > center && start > left) ? start : NULL;
	len = str_trans(tmp, add, len, opt);
	if ((left == NULL && opt->width > 0 && start == NULL) || center != NULL)
		ft_stringaddcn(out, fill, ((center != NULL) ? (opt->width - len) / 2 :
			opt->width - len));
	else if (start != NULL)
		ft_stringaddcn(out, fill, opt->width - out->length);
	ft_stringaddl(out, tmp, len);
	if (left != NULL || opt->width < 0 || center != NULL)
		ft_stringaddcn(out, fill, ((center != NULL) ? (ABS(opt->width) - len)
			/ 2 : ABS(opt->width) - len));
}

void			add_long(t_string *out, t_long add, t_opt *opt)
{
	int				i;
	t_long			tmp;
	char			str[LONG_BUFF];

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

t_bool			is_separator(char c)
{
	return ((c == ',' || c == ';' || c == ':' || c == '_') ? TRUE : FALSE);
}

void			clear_dis(t_opt *opt)
{
	int				i;

	i = -1;
	while (opt->flags[++i] != '\0')
		if (ft_strchr(opt->format->disabled, opt->flags[i]))
			opt->flags[i] = ';';
}
