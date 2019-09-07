/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:28:07 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 15:49:34 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_u0(int *tab, int count)
{
	tab[0] == 1 && tab[1] == 1 ? tab[0] = 0 : 0;
	tab[9] >= tab[7] ? tab[7] = 0 : 0;
	tab[7] > tab[9] ? tab[7] = tab[7] - tab[9] : 0;
	tab[10] == 1 && tab[9] <= 0 ? tab[2] = 0 : 0;
	tab[10] == 1 && tab[9] <= 0 ? tab[0] = -1 : 0;
	tab[7] > 0 && tab[9] > 0 ? tab[2] = 0 : 0;
	while (tab[9] > 0 && tab[1] == 1)
	{
		count = count + cntc('0');
		tab[9]--;
		tab[0] = -1;
	}
	while (tab[7] > 0 && tab[7]--)
	{
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[2] == 1 ? count = count + cntc('0') : 0;
	}
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[9]--;
		tab[0] = -1;
	}
	tab[0] != -1 ? count = count + cntc('0') : 0;
	return (count);
}

int	*sub_u(int *tab, unsigned int n, int count)
{
	if (tab[1] == 1 && tab[9] <= ft_ulintlen(n))
		n < 4294967295 ? ft_putnbrui(n) : write(1, "4294967295", 10);
	if (tab[1] == 1 && tab[9] > ft_ulintlen(n))
		tab[0] = -1;
	if (n != 0)
	{
		n < 4294967295 && tab[9] <= ft_ulintlen(n) ?
			tab[7] = tab[7] - ft_ulintlen(n) : 0;
		n < 4294967295 ? *tab : (tab[7] = tab[7] - 10);
	}
	tab[9] > ft_intlen(n) ? tab[7] = tab[7] - tab[9] : 0;
	while (tab[7] > 0)
	{
		if (((tab[2] == 1 || tab[10] == 1) && n != 0) && tab[10] == 0)
			count = count + cntc('0');
		if ((tab[2] == 0) || (tab[2] == 1 && (n == 0 || tab[10] == 1)))
			count = count + cntc(' ');
		tab[7] = tab[7] - 1;
	}
	tab[11] = count;
	return (tab);
}

int	*sub2_u(int *tab, unsigned int n, int count)
{
	tab = sub_u(tab, n, count);
	count = tab[11];
	tab[9] = tab[9] - ft_ulintlen(n);
	while (tab[9] > 0)
	{
		write(1, "0", 1);
		tab[9]--;
		count++;
	}
	if (tab[1] == 1 && tab[0] == -1)
		n < 4294967295 ? ft_putnbrui(n) : write(1, "4294967295", 10);
	tab[11] = count;
	return (tab);
}

int	printf_u(unsigned int n, const char *format)
{
	int *tab;
	int count;

	tab = get_flags(format);
	count = 0;
	if (n == 0)
		return (count_free(printf_u0(tab, 0), tab));
	tab[1] == 1 && tab[2] == 1 ? tab[2] = 0 : 0;
	if (n == 0 && tab[10] == 1 && tab[9] == 0)
		return (count_free(0, tab));
	if (n == 4294967295 && tab[7] <= 10)
	{
		write(1, "4294967295", 10);
		return (count_free(10, tab));
	}
	tab = sub2_u(tab, n, count);
	count = tab[11];
	n == 4294967295 && tab[1] == 0 ? write(1, "4294967295", 10) : 0;
	if (n == 4294967295 && tab[1] == 0)
		return (count_free((10 + count), tab));
	n < 4294967295 ? (count = count + ft_ulintlen(n)) : 0;
	n < 4294967295 ? 0 : (count = count + 10);
	tab[1] == 0 ? ft_putnbrui(n) : *tab;
	return (count_free(count, tab));
}
