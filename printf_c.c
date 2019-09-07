/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:12:56 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/04 12:33:30 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*sub_c(int *tab, int count, int c)
{
	if (tab[7] > 0)
		while (tab[7] > 0)
		{
			tab[2] == 1 ? write(1, "0", 1) : 0;
			tab[2] == 1 ? count++ : 0;
			tab[2] == 0 ? write(1, " ", 1) : 0;
			tab[2] == 0 ? count++ : 0;
			tab[7] = tab[7] - 1;
		}
	tab[2] == 0 && tab[3] == 1 && tab[1] == 0 ? count = count + disi(c) : 0;
	if (tab[1] == 0)
	{
		if ((c < 0 && tab[2] == 0) || (tab[2] == 1 && tab[3] == 1))
			c = -c;
		ft_putchar(c);
	}
	if (c < 0)
		ft_putchar(c);
	tab[11] = count;
	return (tab);
}

int		printf_c(int c, const char *format)
{
	int i;
	int *tab;
	int count;

	i = 0;
	count = 0;
	tab = get_flags(format);
	tab[0] == 1 && c != 0 ? write(1, " ", 1) : 0;
	if (tab[1] == 1)
	{
		tab[3] == 1 ? count = count + disi((int)c) : 0;
		ft_putchar(c);
	}
	c != 0 ? tab[7] = tab[7] - 1 : 0;
	tab[3] == 1 ? tab[7] = tab[7] - 1 : 0;
	tab[0] == 1 ? tab[7] = tab[7] - 1 : 0;
	c == 0 ? tab[7]-- : 0;
	tab[3] == 1 && tab[2] == 1 ? count = count + disi(c) : 0;
	tab[3] == 1 && tab[2] == 1 ? tab[7]++ : 0;
	tab = sub_c(tab, count, c);
	count = tab[11];
	free(tab);
	return (count + 1);
}
