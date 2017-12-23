/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 13:57:17 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/23 13:57:38 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcslen(wchar_t *s)
{
	int size;
	int sizec;

	size = 0;
	while (s)
		if ((sizec = ft_wclen(*s++)) == -1)
			return (-1);
		else
			size += sizec;
	return (size);
}
