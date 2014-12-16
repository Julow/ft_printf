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
** =============
** A format sequence be like:
**    %[flags][width][.precision]format
** flags can be 0 or more: '#', ' ', '-', '+', '^', '0', '''
** width is a positive integer
** precision is a positive integer or '*', precision start with '.'
** format can be one of "%sSdDoOuUxXicCnp"
** =============
** =
** t_string		*ft_stringf(const char *format, ...);
** void			ft_stringaddf(t_string *str, const char *format, ...);
** =
** ft_stringf
** =============
** Process the format sequence like printf
** =============
** Return a new t_string containing the result.
** =
** =
** ft_stringaddf
** =============
** Like ft_stringf but the result is added to the t_string 'str'
** =
** =
** ft_printf
** =============
** Like ft_stringf but the result is printed to stdout
** =============
** Return the total of char printed.
** =
** =
** ft_printf_fd
** =============
** Like ft_stringf but the result is printed to the fd 'fd'
** =============
** Return the total of char printed.
*/
int				ft_printf(const char *format, ...);
int				ft_printf_fd(const int fd, const char *format, ...);

#endif
