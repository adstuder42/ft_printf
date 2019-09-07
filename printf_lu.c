/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:59:44 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 16:00:15 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_lu(unsigned long int n, const char *format)
{
	int *tab;
	int count;

	tab = get_flags(format);
	if (n == 0)
		return (count_free(printf_u0(tab, 0), tab));
	tab[2] == 1 && tab[1] == 1 ? tab[2] = 0 : 0;
	count = 0;
	if (tab[1] == 1)
		ft_putnbruli(n);
	tab[7] = tab[7] - ft_ulintlen(n);
	tab[7] > 0 && tab[9] > 0 ? tab[2] = 0 : 0;
	while (tab[7] > 0)
	{
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[7]--;
	}
	count = count + ft_ulintlen(n);
	tab[1] == 0 ? ft_putnbruli(n) : 0;
	return (count_free(count, tab));
}
