/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:36:35 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/12 15:23:06 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstr(char *str, t_prtf *data)
{
	int len;	

	if (data->width >= 0)
		str = ft_width(str, data);
	if (data->precision >= 0)
		str = ft_precision(str, data);
	len = -1;
	while (str[++len])
		write (1, &str[len], 1);
	return (len);
}

char	*ft_precision(char *str, t_prtf *data)
{
	int		len;
	char	*s;
	s = str;
	if (data->format == 's')
	{
		s = ft_strsub(s, 0 , data->precision);
		return (s);
	}
	len = ft_strlen(s);
	s = ft_fillwithsep(s, data->precision, '0');
	return (s);
}

char *ft_width(char *str, t_prtf *data)
{
	int		len;
	char	*s;

	s = str;
	len = ft_strlen(s);
	if (data->width >= len)
	{
		if (data->fg_zero && data->precision == -1)
			s = ft_fillwithsep(s, data->width, '0');
		else
			s = ft_fillwithsep(s, data->width, ' ');
	}
	return (s);
}

char *ft_fillwithsep(char *str, int precision, char sep)
{
	char	*new;
	int		i;

	precision -= ft_strlen(str);
	if (!(new = ft_strnew(ft_strlen(str) + precision)))
		return (NULL);
	i = -1;
	while (++i < precision)
		new[i] = sep;
	ft_strcat(new, str);
	return (new);
}
