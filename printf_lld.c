/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:41:59 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 15:59:44 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_lldneg(int *tab, long long int n, int count)
{
	if ((tab[7] > 0 && tab[2] == 1) || tab[9] > 0)
	{
		count = count + disilli(n);
		n = -n;
	}
	tab[1] == 1 ? ft_putnbrlli(n) : tab[1];
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
	tab[1] == 0 ? ft_putnbrlli(n) : tab[1];
	count = count + ft_llintlen(n);
	return (count_free(count, tab));
}

int		*flag_lld(int *tab, long long int n)
{
	tab[0] == 1 && tab[3] == 1 ? tab[0] = 0 : 0;
	tab[1] == 1 && tab[2] == 1 ? tab[2] = 0 : tab[2];
	tab[0] == 1 ? tab[7]-- : tab[7];
	tab[3] == 1 && n > 0 ? tab[7]-- : tab[7];
	if (tab[9] > tab[7])
	{
		tab[7] = 0;
		tab[9] = tab[9] - ft_llintlen(n);
		n < 0 ? tab[9]++ : tab[9];
	}
	else if (tab[7] > tab[9] && tab[10] == 1 && tab[9] > 0)
	{
		tab[9] >= ft_llintlen(n) ? tab[7] = tab[7] - tab[9] : 0;
		tab[9] < ft_llintlen(n) ? tab[7] = tab[7] - ft_llintlen(n) : 0;
		n != 0 ? tab[9] = tab[9] - ft_llintlen(n) : tab[9];
	}
	else if (tab[7] > 0 && tab[9] <= 0 && tab[10] == 1)
		tab[7] = tab[7] - ft_llintlen(n);
	else
	{
		tab[7] = tab[7] - ft_llintlen(n);
		n < 0 && tab[0] == 1 ? tab[7]++ : tab[7];
	}
	return (tab);
}

int		sub_lld(long long int n, int *tab)
{
	int ct;

	ct = 0;
	tab[0] == 1 && tab[3] == 0 ? (ct = ct + cntc(' ')) : tab[0];
	tab[3] == 1 && tab[2] == 1 ? (ct = ct + disilli(n)) : tab[3];
	tab[3] == 1 && tab[2] == 0 && tab[1] == 1 ? (ct = ct + disilli(n)) : tab[3];
	tab[10] == 1 && tab[9] <= 0 ? tab[2] = 0 : 0;
	while (tab[9] > 0 && tab[1] == 1)
	{
		ct = ct + cntc('0');
		tab[9]--;
	}
	tab[1] == 1 ? ft_putnbrlli(n) : tab[1];
	while (tab[7] > 0)
	{
		tab[2] == 1 && tab[9] <= 0 ? ct = ct + cntc('0') : tab[9];
		tab[2] == 1 && tab[9] <= 0 ? tab[9] : (ct = ct + cntc(' '));
		tab[7]--;
	}
	tab[3] == 1 && tab[2] == 0 && tab[1] == 0 ? (ct = ct + disilli(n)) : tab[3];
	return (ct);
}

int		printf_lld(long long int n, const char *format)
{
	int i;
	int *tab;
	int ct;

	i = 0;
	ct = 0;
	n < -9223372036854775807 ? write(1, "-9223372036854775808", 20) : 0;
	if (n < -9223372036854775807)
		return (20);
	if (n < 0)
		return (printf_lldneg(tab = get_flags(format), n, 0));
	if (n == 0)
		return (printf_d0(tab = get_flags(format), 0));
	ct = 0;
	tab = flag_lld(get_flags(format), n);
	ct = ct + sub_lld(n, tab);
	while (tab[9] > 0)
	{
		ct = ct + cntc('0');
		tab[9]--;
	}
	tab[1] == 0 ? ft_putnbrlli(n) : tab[1];
	ct = ct + ft_llintlen(n);
	free(tab);
	return (ct);
}
