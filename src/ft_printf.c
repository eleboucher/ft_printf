/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:48:35 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/06 11:00:37 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	if (format)
	{
		va_start(ap, format);
		len = ft_print(format, ap);
		va_end(ap);
	}
	return (len);
}

int		ft_print(const char *format, va_list ap);
{
	int len;
	char *fmt;
	char *start;

	fmt = (char *)format;
	start = (char *)format;
	len = 0;
	while (fmt)
	{
		if (fmt = '%')
		{
			ft_putnstr(start, fmt - start);
			len += ft_proc_arg(&fmt, ap);
			start = fmt;
		}
		else if (fmt)
		{
			fmt++;
			len++;
		}
	}
	ft_putstrn(start, fmt - start);
	return (len);
}
