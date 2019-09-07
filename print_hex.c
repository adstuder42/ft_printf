/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:47:14 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 19:44:33 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_hex(char *res, int i)
{
	int count;

	count = 0;
	i--;
	i == -1 ? count = count + cntc('0') : i;
	while (i >= 0)
	{
		if (res[i] >= 40 && res[i] <= 57)
			ft_putchar(res[i]);
		if (res[i] == 58)
			ft_putchar('a');
		if (res[i] == 59)
			ft_putchar('b');
		if (res[i] == 60)
			ft_putchar('c');
		if (res[i] == 61)
			ft_putchar('d');
		if (res[i] == 62)
			ft_putchar('e');
		if (res[i] == 63)
			ft_putchar('f');
		count++;
		i--;
	}
	return (count);
}

int		print_hex2(char *res, int i)
{
	int count;

	count = 0;
	i--;
	i == -1 ? count = count + cntc('0') : i;
	while (i >= 0)
	{
		if (res[i] >= 40 && res[i] <= 57)
			ft_putchar(res[i]);
		if (res[i] == 58)
			ft_putchar('A');
		if (res[i] == 59)
			ft_putchar('B');
		if (res[i] == 60)
			ft_putchar('C');
		if (res[i] == 61)
			ft_putchar('D');
		if (res[i] == 62)
			ft_putchar('E');
		if (res[i] == 63)
			ft_putchar('F');
		count++;
		i--;
	}
	return (count);
}
