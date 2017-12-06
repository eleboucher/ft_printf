/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:04:13 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/06 12:31:10 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
#endif
