/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:11:43 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/06 12:47:00 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_proc_arg(char **fmt, va_list ap)
{
	t_prtf			data;

	if (**fmt == '%')
	{
		*fmt++;
		if (**fmt)
		{
			*fmt = ft_parse_args(ap, &data, &modifier, fmt);
			return (ft_print_args(ap, data, modifier, fmt));
		}
	}
	return (0);
}

char	*ft_parse_args(va_list ap, t_prtf *data, char **fmt)
{
	data->width = 0;
	data->precision = 0;
	if (**fmt == '#' || **fmt == ' ' || **fmt == '0' || **fmt == '+' ||
			**fmt == '-')
		data->flags = **fmt++;
	if (ft_isdigit(**fmt))
		data->width = ft_parse_intarg(fmt);
	if (**fmt == '.')
		data->precision = ft_parse_intarg(fmt);
	data->modifier = ft_parse_mod(fmt);
	data->format = **fmt;
	if (**fmt)
		*fmt++;
	return (*fmt);
}

int		ft_parse_intarg(char **fmt)
{
	unsigned int ret;

	ret = 0;
	while (**fmt)
	{
		if (!ft_isdigit(**fmt))
			break ;
		ret = ret * 10 + **fmt++  - '0';
	}
	return (ret);
}

int		ft_parse_mod(char **fmt)
{
	int ret;

	ret = none;
	if (**fmt == 'l')
	{
		ret = md_l;
		if (**fmt++ && **fmt == 'l')
			return (md_db_l);
	}
	if (**fmt == 'h')
	{
		ret = md_l;
		if (**fmt++ && **fmt == 'h')
			return (md_db_h);
	}
	if (**fmt = 'j')
		ret = md_j;
	if (**fmt = 'z')
		ret = md_z;
	if (ret != none && **fmt)
		fmt++;
	return (ret);
}
