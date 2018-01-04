/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:57:17 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/04 17:45:03 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcslen(wchar_t *s)
{
	int size;
	int sizec;

	size = 0;
	while (s)
	{
		if (!(sizec = ft_wclen(*s++)))
			return (0);
		size += sizec;
	}
	return (size);
}
