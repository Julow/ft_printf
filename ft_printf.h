/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:40:48 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/05 17:27:43 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifdef DEBUG_MODE
#  define DEBUG(d, ...) ft_fdprintf(2, d, ##__VA_ARGS__)
# else
#  define DEBUG(d, ...)
# endif

/*
** =============
** A format sequence be like:
**    %[flags][width][.precision]format
** flags can be 0 or more: '#', ' ', '-', '+', '^', '0', ''', '>', 'm', 'M', 'T'
** width is a positive integer
** precision is a positive integer or '*', precision start with '.'
** format can be one of "%sSdDoOuUxXicCnp"
** =============
** =
** =
** ft_printf
** =============
** Process the format sequence like printf and print the result to stdout
** =============
** Return the total of char printed.
** =
** =
** ft_printf_fd
** =============
** Like ft_printf but the result is printed to the fd 'fd'
** =============
** Return the total of char printed.
*/
int				ft_printf(const char *format, ...);
int				ft_fdprintf(const int fd, const char *format, ...);

#endif
