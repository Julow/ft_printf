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

#include "ft_printf.h"

int				ft_strlen(const char *str)
{
	char			*tmp;

	tmp = (char*)str;
	while (*tmp != '\0')
		tmp++;
	return (tmp - str);
}

int				ft_strnequ(char const *s1, char const *s2, int n)
{
	int				i;

	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return ((s1 == s2) ? 1 : 0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (i >= n)
		i = n - 1;
	return ((s1[i] == s2[i]) ? 1 : 0);
}
