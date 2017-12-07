/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:04:13 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/07 11:40:40 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"

typedef struct		s_prtf
{
	int				precision;
	int				width;
	int				modifier;
	char			flags;
	char			format;
}					t_prtf;

enum				e_modifier {
	none,
	md_h,
	md_db_h,
	md_l,
	md_db_l,
	md_j,
	md_z
};
int	debugflags(t_prtf *data);
char	*ft_parse_args(t_prtf *data, char **fmt);
int		ft_parse_intarg(char **fmt);
int		ft_parse_mod(char **fmt);
int		ft_proc_arg(char **fmt, va_list ap);
int		ft_print(const char *format, va_list ap);
int		ft_printf(const char *format, ...);
int		ft_print_args(t_prtf *data, va_list ap);
int		ft_printstr(const char *s);
int		ft_formatstr(t_prtf *data, va_list ap);
int		ft_formatchr(t_prtf *data, va_list ap);
int		ft_formatint(t_prtf *data, va_list ap);
#endif
