/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_0_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:26:46 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/12 13:26:49 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*sub_printf_o0(int *tab, int count)
{
	while (tab[9] > 0 && tab[7] > 0 && tab[1] == 1)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	while (tab[7] > 0)
	{
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[7]--;
	}
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	if (tab[4] == 1)
		tab[1] == 0 ? count = count + cntc('0') : 0;
	tab[11] = count;
	return (tab);
}

int		printf_o0(int *tab)
{
	int count;

	count = 0;
	if ((tab[7] == 1 || tab[7] == 0) && tab[9] == 0 && tab[10] == 0)
		return (count_free(cntc('0'), tab));
	tab[0] == 1 && tab[3] == 1 ? tab[0] = 0 : 0;
	tab[2] == 1 && tab[1] == 1 ? tab[2] = 0 : 0;
	tab[9] >= tab[7] ? tab[7] = 0 : 0;
	tab[7] > tab[9] ? tab[7] = tab[7] - tab[9] : 0;
	if (tab[4] == 1)
	{
		tab[1] == 1 ? count = count + cntc('0') : 0;
		tab[9] > 0 ? tab[9]-- : tab[7]--;
	}
	tab[7] == 0 && tab[9] == 0 && tab[10] == 0 ? count = count + cntc('0') : 0;
	tab[10] == 1 && tab[9] <= 0 && tab[7] > 0 ? tab[2] = 0 : 0;
	tab = sub_printf_o0(tab, count);
	count = tab[11];
	return (count_free(count, tab));
}

int		*sub_printf_d0(int *tab, int count)
{
	while (tab[9] > 0 && tab[1] == 1)
	{
		count = count + cntc('0');
		tab[0] = -1;
		tab[9]--;
	}
	while (tab[7] > 0)
	{
		tab[2] == 0 || tab[9] > 0 ? count = count + cntc(' ') : 0;
		tab[2] == 1 && tab[9] <= 0 ? count = count + cntc('0') : 0;
		tab[0] = -1;
		tab[7]--;
	}
	tab[11] != -1 && tab[3] == 1 ? count = count + cntc('+') : 0;
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[0] = -1;
		tab[9]--;
	}
	tab[0] >= 0 && (tab[9] > 0 || tab[10] == 0) ? count = count + cntc('0') : 0;
	tab[11] = count;
	return (tab);
}

int		*sub_x0(int *tab, int ct)
{
	tab[9] <= 0 && tab[10] == 1 ? tab[2] = 0 : 0;
	tab[9] > 0 && tab[7] > 0 ? tab[2] = 0 : 0;
	while (tab[7] > 0)
	{
		tab[2] == 1 ? ct = ct + cntc('0') : 0;
		tab[2] == 0 ? ct = ct + cntc(' ') : 0;
		tab[7]--;
		tab[0] = -1;
	}
	while (tab[9] > 0)
	{
		ct = ct + cntc('0');
		tab[9]--;
		tab[0] = -1;
	}
	tab[0] != -1 ? ct = ct + cntc('0') : 0;
	tab[11] = ct;
	return (tab);
}
