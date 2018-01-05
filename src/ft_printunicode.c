/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:31:26 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/05 15:59:16 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_formatbigc(t_prtf *data, va_list ap)
{
	wint_t	c;
	int		len;
	char	*str;

	c = va_arg(ap, wchar_t);
	if (!(len = ft_wclen(c)))
		return (-1);
	len = 0;
	if (!(str = ft_wctostr(c)))
		return (-1);
	if (data->fg_minus)
	{
		len += write(1, str, ft_strlen(str));
		len += ft_width(1, data);
	}
	else
	{
		len += ft_width(1, data);
		len += write(1, str, ft_strlen(str));
	}
	return (len);
}

int		ft_formatbigs(t_prtf *data, va_list ap)
{
	wchar_t	*s;
	int		size;
	char	*str;
	char	*tmp;

	size = -1;
	s = va_arg(ap, wchar_t *);
	if (!s)
		return (ft_printstr(ft_strdup("(null)"), data));
	if (!(str = ft_strnew(ft_wcslen(s))))
		return (-1);
	while (s[++size])
	{
		tmp = ft_wctostr(s[size]);
		ft_strcat(str, tmp);
		free(tmp);
	}
	return (ft_printstr(str, data));
}
