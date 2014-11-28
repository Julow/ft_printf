/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:53:13 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/28 17:53:14 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char			ft_stringadd(t_string *str, char *add)
{
	return (ft_stringaddl(str, add, ft_strlen(add)));
}
