/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:36:18 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/06 13:42:15 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	debugflags(t_prtf *data)
{
	printf("precision: %d\nwidth: %d\nmodifier: %d\nflags: %c\nformat: %c\n",data->precision, data->width, data->modifier, data->flags, data->format);
	return (0);
}
