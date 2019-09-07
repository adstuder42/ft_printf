/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:48:03 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 16:25:16 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_dneg(int *tab, int n, int count)
{
	n == -2147483648 ? count = count + 10 : 0;
	tab[2] == 1 && tab[1] == 1 ? tab[2] = 0 : 0;
	tab[2] == 1 && tab[7] >= tab[9] && tab[9] > 0 ? tab[2] = 0 : 0;
	tab[9] < ft_intlen(n) ? tab[9] = ft_intlen(-n) : 0;
	tab[9] = tab[9] - ft_intlen(-n);
	tab[7] = tab[7] - (ft_intlen(n) + tab[9]);
	tab[2] == 1 ? cntc('-') : 0;
	tab[1] == 1 && tab[9] > 0 ? tab[1] = 0 : 0;
	tab[1] == 1 && tab[9] <= 0 ? ft_putnbr(n) : 0;
	while (tab[7] > 0)
	{
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[7]--;
	}
	n != -2147483648 && tab[2] == 0 && tab[1] == 0 ?
		count = count + cntc('-') : count++;
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	tab[1] == 0 ? ft_putnbr(-n) : 0;
	count = count + ft_intlen(n) - 1;
	return (count_free(count, tab));
}

int		printf_d0(int *tab, int count)
{
	tab[2] == 1 && tab[1] == 1 ? tab[2] = 0 : 0;
	tab[0] == 1 && tab[3] == 1 ? tab[0] = 0 : 0;
	tab[0] == 1 || tab[3] == 1 ? tab[7]-- : 0;
	tab[9] >= tab[7] ? tab[7] = 0 : 0;
	tab[7] > tab[9] ? tab[7] = tab[7] - tab[9] : 0;
	tab[10] == 1 && tab[9] <= 0 ? tab[2] = 0 : 0;
	tab[0] == 1 ? count = count + cntc(' ') : 0;
	if (tab[3] == 1)
	{
		if (tab[9] <= 0 || tab[7] <= 0 || tab[1] == 1)
		{
			count = count + cntc('+');
			tab[11] = -1;
		}
	}
	tab[7] > 0 && tab[10] == 0 ? count = count + cntc('0') : 0;
	tab[7] > 0 && tab[10] == 0 ? tab[7]-- : 0;
	tab = sub_printf_d0(tab, count);
	count = tab[11];
	return (count_free(count, tab));
}

int		*flag_d(int *tab, int n)
{
	tab[0] == 1 && tab[3] == 1 ? tab[0] = 0 : 0;
	tab[1] == 1 && tab[2] == 1 ? tab[2] = 0 : tab[2];
	tab[0] == 1 ? tab[7]-- : tab[7];
	tab[3] == 1 && n > 0 ? tab[7]-- : tab[7];
	if (tab[9] > tab[7])
	{
		tab[7] = 0;
		tab[9] = tab[9] - ft_intlen(n);
		n < 0 ? tab[9]++ : tab[9];
	}
	else if (tab[7] > tab[9] && tab[10] == 1 && tab[9] > 0)
	{
		tab[9] >= ft_intlen(n) ? tab[7] = tab[7] - tab[9] : 0;
		tab[9] < ft_intlen(n) ? tab[7] = tab[7] - ft_intlen(n) : 0;
		n != 0 ? tab[9] = tab[9] - ft_intlen(n) : tab[9];
	}
	else if (tab[7] > 0 && tab[9] <= 0 && tab[10] == 1)
		tab[7] = tab[7] - ft_intlen(n);
	else
	{
		tab[7] = tab[7] - ft_intlen(n);
		n < 0 && tab[0] == 1 ? tab[7]++ : tab[7];
	}
	return (tab);
}

int		sub_d(int n, int *tab)
{
	int ct;

	ct = 0;
	tab[0] == 1 && tab[3] == 0 ? (ct = ct + cntc(' ')) : tab[0];
	tab[3] == 1 && tab[2] == 1 ? (ct = ct + disi(n)) : tab[3];
	tab[3] == 1 && tab[2] == 0 && tab[1] == 1 ? (ct = ct + disi(n)) : tab[3];
	tab[10] == 1 && tab[9] <= 0 ? tab[2] = 0 : 0;
	while (tab[9] > 0 && tab[1] == 1)
	{
		ct = ct + cntc('0');
		tab[9]--;
	}
	tab[1] == 1 ? ft_putnbr(n) : tab[1];
	while (tab[7] > 0)
	{
		tab[2] == 1 && tab[9] <= 0 ? ct = ct + cntc('0') : 0;
		tab[2] == 1 && tab[9] <= 0 ? 0 : (ct = ct + cntc(' '));
		tab[7]--;
	}
	tab[3] == 1 && tab[2] == 0 && tab[1] == 0 ? (ct = ct + disi(n)) : tab[3];
	return (ct);
}

int		printf_d(int n, const char *format)
{
	int i;
	int *tab;
	int ct;

	i = 0;
	if (n < 0)
		return (printf_dneg(tab = get_flags(format), n, 0));
	if (n == 0)
		return (printf_d0(tab = get_flags(format), 0));
	ct = 0;
	tab = flag_d(get_flags(format), n);
	ct = ct + sub_d(n, tab);
	while (tab[9] > 0)
	{
		ct = ct + cntc('0');
		tab[9]--;
	}
	tab[1] == 0 ? ft_putnbr(n) : tab[1];
	ct = ct + ft_intlen(n);
	free(tab);
	return (ct);
}
