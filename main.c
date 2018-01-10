/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:42:34 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/10 10:44:43 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>
int	main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	char c;
	ft_printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
	ft_printf("\n");
	printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0);
}
