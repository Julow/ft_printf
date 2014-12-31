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

# include <stdarg.h>

# define HASF(c)	(ft_strchr(opt->flags, (c)) != NULL)

# define LONG_BUFF	(40)

typedef struct	s_format
{
	char			name;
	void			(*func)();
	char			*disabled;
}				t_format;

typedef struct	s_opt
{
	char			*flags;
	int				width;
	int				preci;
	char const		*length;
	t_format		*format;
}				t_opt;

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
** dutils.c
*/
void			stringaddid(t_string *str, long double nbr);
void			stringaddd(t_string *str, long double d, int preci, t_opt *opt);
void			stringaddde(t_string *str, long double d, int pre, t_opt *opt);

/*
** utils.c
*/
void			add_string(t_string *out, char *add, int len, t_opt *opt);
void			add_long(t_string *out, t_long add, t_opt *opt);
void			clear_dis(t_opt *opt);
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
void			flag_e(t_string *out, t_opt *opt, va_list *ap);
void			flag_f(t_string *out, t_opt *opt, va_list *ap);
void			flag_b(t_string *out, t_opt *opt, va_list *ap);
void			flag_r(t_string *out, t_opt *opt, va_list *ap);

#endif
