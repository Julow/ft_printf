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

# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FORMATS	(7)
# define METAS		(5)

# define LONG		long long int

typedef LONG	t_long;

typedef struct	s_string
{
	char			*content;
	int				length;
	int				alloc_length;
}				t_string;

typedef struct	s_opt
{
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
** string.c
*/
t_string		*ft_stringnew(void);
char			ft_stringaddc(t_string *str, char c);
char			ft_stringaddcn(t_string *str, char c, int n);
char			ft_stringadd(t_string *str, char *add);
char			ft_stringaddl(t_string *str, char *add, int len);
char			ft_stringext(t_string *str, int need);

/*
** utils.c
*/
int				ft_isdigit(char c);
char			add_string(t_string *out, char *add, int len, t_opt *opt);
char			add_long(t_string *out, t_long add, t_opt *opt);
int				ft_atoin(char *str, int len);

/*
** strutils.c
*/
char			*ft_strsub(char const *s, int start, int len);
int				ft_strlen(const char *str);
int				ft_strnequ(char const *s1, char const *s2, int n);
char			*ft_strchr(const char *s, int c);

/*
** flags
*/
void			flag_percent(t_string *out, t_opt *opt, va_list *ap);
void			flag_s(t_string *out, t_opt *opt, va_list *ap);
void			flag_ss(t_string *out, t_opt *opt, va_list *ap);
void			flag_d(t_string *out, t_opt *opt, va_list *ap);
void			flag_dd(t_string *out, t_opt *opt, va_list *ap);
void			flag_c(t_string *out, t_opt *opt, va_list *ap);
void			flag_cc(t_string *out, t_opt *opt, va_list *ap);
void			flag_n(t_string *out, t_opt *opt, va_list *ap);

#endif
