/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:20:58 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/07 11:59:36 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int		ft_printstr(const char *s)
{
	int i;

	i = -1;
	while (s[++i] != '\0')
		write(1, &s[i], 1);
	return (i);
}

int		ft_formatstr(t_prtf *data, va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	if (!s)
		return (ft_printstr("(null)"));
	if (data->format == 'S' || (data->format == 's' && data->flags == md_l))
			return (ft_printstr(s));
	if (data->format == 's')
		return (ft_printstr(s));
	return (0);
}

int		ft_formatchr(t_prtf *data, va_list ap)
{
	char c;
	
	(void)data;
	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int		ft_formatint(t_prtf *data, va_list ap)
{
	long long i;

	i = va_arg(ap, long long);
	if (data->format == 'd' || data->format == 'i')
		return(ft_printstr(ft_lltoa_base((int)i,10)));
	return (0);
}
