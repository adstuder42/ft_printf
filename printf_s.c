/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 17:33:34 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/09 18:54:03 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*flag_s(int *tab, char *str)
{
	if (str == NULL)
		return (tab);
	if (tab[10] == 1 && tab[9] == 0 && tab[7] == 0)
		return (tab);
	if ((tab[10] == 1) && (tab[9] < (int)ft_strlen(str)))
		tab[7] = tab[7] - tab[9];
	else
		tab[7] = tab[7] - ft_strlen(str);
	return (tab);
}

int		*sub_s(int *tab, int count, char *str)
{
	tab[9] <= 0 && tab[10] == 1 ? count = count - ft_strlen(str) : 0;
	tab[1] == 1 && str != NULL ? count = count + printprec(str, tab) : 0;
	tab[1] == 1 && str != NULL ? tab[9] = 0 : 0;
	while (tab[7] > 0)
	{
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[7]--;
	}
	tab[9] == 0 && tab[1] == 0 && tab[10] == 0 ? ft_putstr(str) : 0;
	tab[9] == 0 && tab[1] == 0 ? count = count + ft_strlen(str) : 0;
	tab[11] = count;
	return (tab);
}

int		printf_s(char *str, const char *format)
{
	int *tab;
	int count;
	int i;

	count = 0;
	i = 0;
	tab = flag_s(get_flags(format), str);
	if (str == NULL)
	{
		tab[7] = tab[7] - tab[9];
		return (print_null(tab));
	}
	tab = sub_s(tab, count, str);
	count = tab[11];
	while (tab[9] > 0)
	{
		if (str[i] == '\0')
			return (count_free(count, tab));
		count = count + cntc(str[i]);
		i++;
		tab[9]--;
	}
	free(tab);
	return (count);
}
