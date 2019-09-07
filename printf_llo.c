/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_llo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:08:49 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 16:00:46 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*octoconv(unsigned long long int n)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	res = make_str(res);
	while (n > 0)
	{
		res[i] = (n % 8) + 48;
		n = n / 8;
		i++;
	}
	res[i] = n % 8;
	res[i + 1] = '\0';
	return (res);
}

int		*sub_llo(int *tab, int count, int i, char *res)
{
	while (tab[9] > 0)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	count = count + print_octal(res, i, tab);
	while (tab[7] > 0 && tab[1] == 1)
	{
		tab[2] == 1 ? (count = count + cntc('0')) : 0;
		tab[2] == 1 ? 0 : (count = count + cntc(' '));
		tab[7]--;
	}
	tab[11] = count;
	return (tab);
}

int		printf_llo(unsigned long long int n, const char *format)
{
	int		i;
	char	*res;
	int		count;
	int		*tab;

	count = 0;
	tab = get_flags(format);
	tab[7] > 0 && tab[9] > 0 ? tab[2] = 0 : 0;
	if (n == 0)
		return (printf_o0(tab));
	res = octoconv(n);
	i = ft_strlen(res);
	tab = flag_o(tab, res);
	while (tab[7] > 0 && tab[1] == 0)
	{
		tab[2] == 1 ? 0 : (count = count + cntc(' '));
		tab[2] == 1 ? (count = count + cntc('0')) : 0;
		tab[7]--;
	}
	tab[4] == 1 && tab[9] > 0 ? tab[9]-- : tab[9];
	tab = sub_llo(tab, count, i, res);
	count = tab[11];
	free(res);
	free(tab);
	return (count);
}
