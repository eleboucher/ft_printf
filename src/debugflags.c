/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:36:18 by elebouch          #+#    #+#             */
/*   Updated: 2017/12/12 13:58:33 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	debugflags(t_prtf *data)
{
	printf("precision: %d\nwidth: %d\nmodifier: %d\nformat: %c\n0: %d\n#: %d\n-: %d\nspace: %d\n+: %d\n",data->precision, data->width, data->modifier, data->format, data->fg_zero, data->fg_hashtag, data->fg_minus, data->fg_space, data->fg_plus);
	return (0);
}
