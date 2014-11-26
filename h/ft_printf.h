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

typedef struct	s_string
{
	char			*content;
	int				length;
	int				alloc_length;
}				t_string;

typedef struct	s_format
{
	char			name;
	void			(*f)(t_string*, va_list*);
}				t_format;

/*
** ft_printf.c
*/
t_string		*ft_format(const char *format, ...);
int				ft_printf(const char *format, ...);
int				ft_printf_fd(const int fd, const char *format, ...);

/*
** formater.c
*/
void			formater(t_string *out, const char *format, va_list ap);

/*
** string.c
*/
t_string		*ft_stringnew(void);
char			ft_stringext(t_string *str, int need);

/*
** flags
*/
void			flag_n(t_string *out, va_list *ap);

#endif
