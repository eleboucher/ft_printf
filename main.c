/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:42:34 by elebouch          #+#    #+#             */
/*   Updated: 2018/01/05 16:02:57 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
int	main(void)
{
	int i = 42;
	char *str = "coucou";
	setlocale(LC_ALL, "");
	ft_printf("%C", 0);
	printf("%C", 0);
}
