/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:18:20 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 19:17:47 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		sub_x2(int *tab, int count, char *res, int i)
{
	tab[1] == 1 && tab[2] == 1 ? tab[2] = 0 : tab[2];
	if (tab[4] == 1)
		tab[7] = tab[7] - 2;
	while (tab[9] > 0 && (tab[7] <= 0 || tab[1] == 1))
	{
		count = count + cntc('0');
		tab[9]--;
	}
	tab[1] == 1 ? (count = count + print_hex2(res, i)) : tab[1];
	while (tab[7] > 0)
	{
		tab[2] == 0 ? (count = count + cntc(' ')) : *tab;
		tab[2] == 0 ? *tab : (count = count + cntc('0'));
		tab[7]--;
	}
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	tab[4] == 1 && tab[2] == 0 ? write(1, "0X", 2) : *tab;
	tab[4] == 1 && tab[2] == 0 ? count = count + 2 : *tab;
	tab[1] == 0 ? (count = count + print_hex2(res, i)) : tab[1];
	return (count);
}

int		printf_x2(unsigned int n, const char *format)
{
	int		i;
	char	*res;
	int		count;
	int		*tab;

	tab = get_flags(format);
	if (n == 0)
		return (count_free(printf_x0(tab, 0), tab));
	res = hexconv(n);
	i = ft_strlen(res);
	count = 0;
	tab[4] == 1 && tab[1] == 1 ? write(1, "0X", 2) : *tab;
	tab[4] == 1 && tab[1] == 1 ? count = count + 2 : *tab;
	tab[4] == 1 && tab[1] == 1 ? tab[7] = tab[7] - 2 : *tab;
	tab[4] == 1 && tab[1] == 1 ? tab[4] = 0 : *tab;
	tab[10] == 1 && tab[2] == 1 ? tab[2] = 0 : tab[2];
	if (tab[9] == 0 && tab[10] == 1 && i == 0)
		return (count_free_x(count, tab, res));
	tab = flag_x(tab, i);
	tab[4] == 1 && (tab[2] == 1 || tab[9] > 0) ? write(1, "0X", 2) : *tab;
	tab[4] == 1 && (tab[2] == 1 || tab[9] > 0) ? count = count + 2 : *tab;
	tab[4] == 1 && (tab[2] == 1 || tab[9] > 0) ? tab[7] = tab[7] - 2 : *tab;
	tab[4] == 1 && (tab[2] == 1 || tab[9] > 0) ? tab[4] = 0 : *tab;
	count = sub_x2(tab, count, res, i);
	return (count_free_x(count, tab, res));
}
