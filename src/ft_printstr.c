/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:36:35 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/14 17:14:03 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printstr(char *str, t_prtf *data)
{
	int len;

	if (data->fg_hashtag && !data->fg_zero)
	{
		if (data->format == 'x')
			str = ft_strjoin("0x", str);
		else if (data->format == 'X')
			str = ft_strjoin("0X", str);
		else if (data->format == 'o')
			data->precision += 1;
	}
	if (data->fg_space && !data->fg_plus && (data->format == 'd' ||
				data->format == 'i'))
		str = ft_strjoin(" ", str);
	if (data->fg_plus && !ft_strchr(str, '-'))
		str = ft_strjoin("+", str);
	if (data->width >= 0)
		str = ft_width(str, data);
	if (data->precision >= 0)
		str = ft_precision(str, data);
	len = -1;
	while (str[++len])
		write(1, &str[len], 1);
	return (len);
}

char	*ft_precision(char *str, t_prtf *data)
{
	int		len;
	char	*s;

	s = str;
	if (data->format == 's')
	{
		s = ft_strsub(s, 0, data->precision);
		return (s);
	}
	len = ft_strlen(s);
	s = ft_fillwithsep(s, data->precision, '0', 0);
	return (s);
}

char	*ft_width(char *str, t_prtf *data)
{
	int		len;
	char	*s;

	s = str;
	len = ft_strlen(s);
	if (data->width >= len)
	{
		if (data->fg_zero && data->precision == -1 && !data->fg_minus)
			s = ft_fillwithsep(s, data->width, '0', 0);
		else if (data->fg_minus)
			s = ft_fillwithsep(s, data->width, ' ', len);
		else
			s = ft_fillwithsep(s, data->width, ' ', 0);
	}
	return (s);
}

char	*ft_fillwithsep(char *str, int precision, char sep, int start)
{
	char	*new;
	int		i;
	int		j;

	precision -= ft_strlen(str);
	if (!(new = ft_strnew(ft_strlen(str) + precision)))
		return (NULL);
	j = -1;
	while (++j < (int)ft_strlen(str) + precision)
		new[j] = sep;
	j = -1;
	i = (!start) ? precision : 0;
	while (++j < (int)ft_strlen(str))
		new[i++] = str[j];
	return (new);
}
