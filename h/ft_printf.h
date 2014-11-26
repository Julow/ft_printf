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

# include <stddef.h>
# include <stdarg.h>

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

typedef struct	s_meta
{
	char			*name;
	char			*value;
}				t_meta;

/*
** ft_printf.c
*/
t_string		*ft_format(const char *format, ...);
int				ft_printf(const char *format, ...);
int				ft_printf_fd(const int fd, const char *format, ...);

/*
** formater.c
*/
void			formater(t_string *out, char *format, va_list *ap);

/*
** string.c
*/
t_string		*ft_stringnew(void);
char			ft_stringaddl(t_string *str, char *add, int len);
char			ft_stringext(t_string *str, int need);

/*
** utils.c
*/
int				ft_strlen(const char *str);
int				ft_strnequ(char const *s1, char const *s2, int n);

/*
** flags
*/
void			flag_n(t_string *out, va_list *ap);

#endif
