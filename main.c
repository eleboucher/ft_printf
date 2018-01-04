/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:42:34 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/04 17:28:06 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = 42;
	char *str = "coucou";
	ft_printf("%lc", 0x4e6);
	ft_printf("%C", 0x6f);
//	printf("%C", 0x6f);
}
