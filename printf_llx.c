/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_llx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:40:35 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 19:25:59 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*hexconv_ulli(unsigned long long int n)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	res = make_str(res);
	while (n > 0)
	{
		res[i] = (n % 16) + 48;
		n = n / 16;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		sub_llx(int *tab, int count, char *res, int i)
{
	if (tab[4] == 1)
		tab[7] = tab[7] - 2;
	while (tab[9] > 0 && (tab[7] <= 0 || tab[1] == 1))
	{
		count = count + cntc('0');
		tab[9]--;
	}
	tab[1] == 1 ? (count = count + print_hex(res, i)) : tab[1];
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
	tab[4] == 1 && tab[2] == 0 ? write(1, "0x", 2) : *tab;
	tab[4] == 1 && tab[2] == 0 ? count = count + 2 : *tab;
	tab[1] == 0 ? (count = count + print_hex(res, i)) : tab[1];
	return (count);
}

int		printf_llx(unsigned long long int n, const char *format)
{
	int		i;
	char	*res;
	int		count;
	int		*tab;

	tab = get_flags(format);
	if (n == 0)
		return (count_free(printf_x0(tab, 0), tab));
	res = hexconv_ulli(n);
	i = ft_strlen(res);
	count = 0;
	tab[4] == 1 && tab[1] == 1 ? write(1, "0x", 2) : 0;
	tab[4] == 1 && tab[1] == 1 ? count = count + 2 : 0;
	tab[4] == 1 && tab[1] == 1 ? tab[7] = tab[7] - 2 : 0;
	tab[4] == 1 && tab[1] == 1 ? tab[4] = 0 : 0;
	tab[10] == 1 && tab[2] == 1 ? tab[2] = 0 : tab[2];
	if (tab[9] == 0 && tab[10] == 1 && i == 0)
		return (count_free_x(count, tab, res));
	tab = flag_x(tab, i);
	tab[4] == 1 && (tab[2] == 1 || tab[9] > 0) ? write(1, "0x", 2) : *tab;
	tab[4] == 1 && (tab[2] == 1 || tab[9] > 0) ? count = count + 2 : *tab;
	tab[4] == 1 && (tab[2] == 1 || tab[9] > 0) ? tab[7] = tab[7] - 2 : *tab;
	tab[4] == 1 && (tab[2] == 1 || tab[9] > 0) ? tab[4] = 0 : *tab;
	count = sub_llx(tab, count, res, i);
	return (count_free_x(count, tab, res));
}
