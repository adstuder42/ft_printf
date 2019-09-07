/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:36:19 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/10 22:43:41 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_ldneg(int *tab, long int n, int count)
{
	unsigned long long	nb;

	nb = -n;
	if (tab[7] == 0 || (tab[7] >= 0 && tab[2] == 0) || tab[9] >= 0 ||
			tab[1] == 1)
	{
		count = count + disi(-1);
		n = -n;
	}
	tab[1] == 1 ? ft_putnbruli(nb) : tab[1];
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	while (tab[7] > 0)
	{
		tab[2] == 0 ? (cntc(' ')) : (cntc('0'));
		tab[2] == 0 ? (count++) : (count++);
		tab[7]--;
	}
	tab[1] == 0 ? ft_putnbruli(nb) : tab[1];
	return (count_free((count + ft_ulintlen(nb)), tab));
}

int		*flag_ld(int *tab, long int n)
{
	tab[0] == 1 && tab[3] == 1 ? tab[0] = 0 : 0;
	tab[1] == 1 && tab[2] == 1 ? tab[2] = 0 : tab[2];
	tab[0] == 1 ? tab[7]-- : tab[7];
	tab[3] == 1 && n > 0 ? tab[7]-- : tab[7];
	if (tab[9] > tab[7])
	{
		tab[7] = 0;
		tab[9] = tab[9] - ft_lintlen(n);
		n < 0 ? tab[9]++ : tab[9];
	}
	else if (tab[7] > tab[9] && tab[10] == 1 && tab[9] > 0)
	{
		tab[9] >= ft_lintlen(n) ? tab[7] = tab[7] - tab[9] : 0;
		tab[9] < ft_lintlen(n) ? tab[7] = tab[7] - ft_lintlen(n) : 0;
		n != 0 ? tab[9] = tab[9] - ft_lintlen(n) : tab[9];
	}
	else if (tab[7] > 0 && tab[9] <= 0 && tab[10] == 1)
		tab[7] = tab[7] - ft_lintlen(n);
	else
	{
		tab[7] = tab[7] - ft_lintlen(n);
		n < 0 && tab[0] == 1 ? tab[7]++ : tab[7];
	}
	return (tab);
}

int		sub_ld(long int n, int *tab)
{
	int ct;

	ct = 0;
	tab[0] == 1 && tab[3] == 0 ? (ct = ct + cntc(' ')) : tab[0];
	tab[3] == 1 && tab[2] == 1 ? (ct = ct + disili(n)) : tab[3];
	tab[3] == 1 && tab[2] == 0 && tab[1] == 1 ? (ct = ct + disili(n)) : tab[3];
	tab[10] == 1 && tab[9] <= 0 ? tab[2] = 0 : 0;
	while (tab[9] > 0 && tab[1] == 1)
	{
		ct = ct + cntc('0');
		tab[9]--;
	}
	tab[1] == 1 ? ft_putnbrli(n) : tab[1];
	while (tab[7] > 0)
	{
		tab[2] == 1 && tab[9] <= 0 ? ct = ct + cntc('0') : tab[9];
		tab[2] == 1 && tab[9] <= 0 ? tab[9] : (ct = ct + cntc(' '));
		tab[7]--;
	}
	tab[3] == 1 && tab[2] == 0 && tab[1] == 0 ? (ct = ct + disili(n)) : tab[3];
	return (ct);
}

int		printf_ld(long int n, const char *format)
{
	int i;
	int *tab;
	int ct;

	i = 0;
	if (n < 0)
		return (printf_ldneg(tab = get_flags(format), n, 0));
	if (n == 0)
		return (printf_d0(tab = get_flags(format), 0));
	ct = 0;
	tab = flag_ld(get_flags(format), n);
	ct = ct + sub_ld(n, tab);
	while (tab[9] > 0)
	{
		ct = ct + cntc('0');
		tab[9]--;
	}
	tab[1] == 0 ? ft_putnbrli(n) : tab[1];
	ct = ct + ft_lintlen(n);
	free(tab);
	return (ct);
}
