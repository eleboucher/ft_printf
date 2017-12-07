/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:11:43 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/07 11:41:23 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_proc_arg(char **fmt, va_list ap)
{
	t_prtf			data;

	(void)ap;
	if (**fmt == '%')
	{
		(*fmt)++;
		if (**fmt)
		{
			*fmt = ft_parse_args(&data, fmt);
			return (ft_print_args(&data, ap));
		}
	}
	return (0);
}

char	*ft_parse_args(t_prtf *data, char **fmt)
{
	data->width = 0;
	data->precision = 0;
	if (**fmt == '#' || **fmt == ' ' || **fmt == '0' || **fmt == '+' ||
			**fmt == '-')
		data->flags = *(*fmt)++;
	if (ft_isdigit(**fmt))
		data->width = ft_parse_intarg(fmt);
	if (**fmt == '.')
	{
		(*fmt)++;
		data->precision = ft_parse_intarg(fmt);
	}
	data->modifier = ft_parse_mod(fmt);
	while (ft_isspace(**fmt))
		(*fmt)++;
	data->format = **fmt;
	if (**fmt)
		(*fmt)++;
	return (*fmt);
}

int		ft_parse_intarg(char **fmt)
{
	unsigned int ret;

	ret = 0;
	while (**fmt != '\0')
	{
		if (!ft_isdigit(**fmt))
			break ;
		ret = ret * 10 + *(*fmt)++  - '0';
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
		if (*(*fmt)++ && **fmt == 'l')
			ret = md_db_l;
	}
	if (**fmt == 'h')
	{
		ret = md_l;
		if (*(*fmt)++ && **fmt == 'h')
			ret = md_db_h;
	}
	if (**fmt == 'j')
		ret = md_j;
	if (**fmt == 'z')
		ret = md_z;
	if (ret != none && **fmt)
		(*fmt)++;
	return (ret);
}

int		ft_print_args(t_prtf *data, va_list ap)
{
	if (data->format == '%')
	{
		ft_putchar(data->format);
		return (1);
	}
	else if (data->format == 's' || data->format == 'S')
		return (ft_formatstr(data, ap));
	else if (data->format == 'c' || data->format == 'C')
		return (ft_formatchr(data, ap));
	else if (data->format == 'd' || data->format == 'i' || data->format == 'o'
		|| data->format == 'u' || data->format == 'x' || data->format == 'X')
		return (ft_formatint(data, ap));
	//else if (data->format == 'D' || data->format == 'O' || data->format == 'U')
	//	return (ft_formatlong(data, ap));
	return (0);
}
