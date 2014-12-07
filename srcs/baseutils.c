/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:10:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 17:10:17 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char			*ft_itobase(t_long nb, char *base)
{
	int				base_len;
	char			*str;
	int				i;
	t_long			tmp;

	base_len = ft_strlen(base);
	if (nb == 0 || base_len == 0)
		return (ft_strdup("0"));
	tmp = nb;
	i = (nb < 0) ? 2 : 1;
	while ((tmp /= base_len) != 0)
		i++;
	str = MAL(char, i);
	str[i] = '\0';
	tmp = nb;
	while (--i >= 0)
	{
		str[i] = base[((nb < 0) ? -(tmp % base_len) : tmp % base_len)];
		tmp /= base_len;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}

t_long			ft_basetoi(char *str, char *base)
{
	int				i;
	int				base_len;
	t_long			nb;

	base_len = ft_strlen(base);
	nb = 0;
	i = (str[0] == '-' && ft_strchri(base, '-') == -1) ? 0 : -1;
	while (str[++i] != '\0')
	{
		nb *= base_len;
		nb += ft_strchri(base, str[i]);
	}
	if (str[0] == '-' && ft_strchri(base, '-') == -1)
		nb *= -1;
	return (nb);
}
