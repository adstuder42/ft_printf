/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:25:14 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/12 13:05:32 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cntc(char c)
{
	write(1, &c, 1);
	return (1);
}

int		disi(int n)
{
	if (n >= 0)
		ft_putchar('+');
	else
		ft_putchar('-');
	return (1);
}

int		disili(long int n)
{
	if (n >= 0)
		ft_putchar('+');
	else
		ft_putchar('-');
	return (1);
}

int		disilli(long long int n)
{
	if (n >= 0)
		ft_putchar('+');
	else
		ft_putchar('-');
	return (1);
}

int		print_sign(int n, int *tab)
{
	if (tab[3] == 1 && tab[2] == 0)
	{
		disi(n);
		tab[3] = -1;
		tab[7]--;
	}
	else if (tab[3] == 0 && tab[7] == 0 && n < 0)
	{
		disi(n);
		tab[3] = -1;
		tab[7]--;
	}
	else if (tab[2] == 1 && n < 0)
	{
		disi(n);
		tab[3] = -1;
	}
	else if (tab[2] == 1 && tab[3] == 1)
	{
		disi(n);
		tab[7]--;
	}
	free(tab);
	return (1);
}
