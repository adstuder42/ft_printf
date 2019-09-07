/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_0_aux2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:35:14 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/12 13:35:22 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_d0_minus0(int *tab, int count)
{
	if (tab[7] > 0 && tab[9] <= 0)
	{
		count = count + cntc('0');
		tab[7]--;
		while (tab[7] > 0)
		{
			count = count + cntc(' ');
			tab[7]--;
		}
		return (count);
	}
	else
	{
		while (tab[9] > 0)
		{
			count = count + cntc('0');
			tab[9]--;
		}
		while (tab[7] > 0)
		{
			count = count + cntc(' ');
			tab[7]--;
		}
		return (count);
	}
}

int		printf_sub_d0(int *tab, int count)
{
	while (tab[9] > 0 && tab[1] == 1 && tab[2] == 1)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	while (tab[7] > 0)
	{
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[7]--;
		tab[0] = -1;
	}
	tab[3] == 1 && tab[6] != -1 && tab[1] == 0 ? count = count + cntc('+') : 0;
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[9]--;
		tab[0] = -1;
	}
	tab[0] != -1 ? count = count + cntc('0') : 0;
	return (count);
}

int		*printf_subx0(int *tab, int count)
{
	while (--tab[9] > 0 && tab[1] == 1)
		count = count + cntc('0');
	while (tab[7] > 0)
	{
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[7]--;
	}
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	tab[1] == 0 && tab[10] != -1 ? (count = count + cntc('0')) : 0;
	tab[1] == 0 && tab[10] == -1 ? (count = count + cntc(' ')) : 0;
	tab[11] = count;
	return (tab);
}
