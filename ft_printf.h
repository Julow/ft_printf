/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:40:48 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/26 13:40:49 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** t_string		*ft_format(const char *format, ...);
** t_bool		ft_stringf(t_string *str, const char *format, ...);
*/
int				ft_printf(const char *format, ...);
int				ft_printf_fd(const int fd, const char *format, ...);

#endif
