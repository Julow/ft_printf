/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:23:37 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/27 11:23:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include "libft.h"

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <sys/types.h>
# include <inttypes.h>

typedef struct	s_opt
{
	t_format		*format;
	char			*flags;
	int				width;
	int				precision;
	char const		*length;
}				t_opt;

typedef struct	s_format
{
	char			name;
	void			(*func)(t_string*, t_opt *opt, va_list*);
}				t_format;

typedef struct	s_meta
{
	char			*name;
	char			*value;
}				t_meta;

/*
** parse_format.c
*/
int				parse_format(t_string *out, char *format, va_list *ap);

/*
** parse_meta.c
*/
int				parse_meta(t_string *out, char *format);

/*
** utils.c
*/
void			add_string(t_string *out, char *add, int len, t_opt *opt);
void			add_long(t_string *out, t_long add, t_opt *opt);
int				ft_atoin(char *str, int len);

/*
** argsutils.c
*/
t_long			get_arg(t_opt *opt, va_list *ap);
t_ulong			get_unsigned_arg(t_opt *opt, va_list *ap);
long double		get_float_arg(t_opt *opt, va_list *ap);

/*
** flags
*/
void			flag_percent(t_string *out, t_opt *opt, va_list *ap);
void			flag_s(t_string *out, t_opt *opt, va_list *ap);
void			flag_d(t_string *out, t_opt *opt, va_list *ap);
void			flag_o(t_string *out, t_opt *opt, va_list *ap);
void			flag_u(t_string *out, t_opt *opt, va_list *ap);
void			flag_x(t_string *out, t_opt *opt, va_list *ap);
void			flag_c(t_string *out, t_opt *opt, va_list *ap);
void			flag_n(t_string *out, t_opt *opt, va_list *ap);
void			flag_p(t_string *out, t_opt *opt, va_list *ap);

#endif
