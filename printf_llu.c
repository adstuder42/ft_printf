/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_llu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:35:11 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 10:29:32 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_llu(unsigned long long int n, const char *format)
{
	int *tab;
	int count;

	tab = get_flags(format);
	if (n == 0)
		return (count_free(printf_u0(tab, 0), tab));
	tab[1] == 1 && tab[2] == 1 ? tab[2] = 0 : 0;
	count = 0;
	if (tab[1] == 1)
		ft_putnbruli(n);
	tab[7] = tab[7] - ft_lintlen(n);
	tab[9] > 0 && tab[7] > 0 ? tab[2] = 0 : 0;
	while (tab[7] > 0)
	{
		tab[2] == 1 ? (write(1, "0", 1)) : tab[2];
		tab[2] == 1 ? count++ : tab[2];
		tab[2] == 0 ? (write(1, " ", 1)) : tab[2];
		tab[2] == 0 ? count++ : tab[2];
		tab[7] = tab[7] - 1;
	}
	count = count + ft_ulintlen(n);
	if (tab[1] == 0)
		ft_putnbruli(n);
	return (count_free(count, tab));
}
