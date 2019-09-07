/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:10:38 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/05 17:48:25 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_pc(const char *format)
{
	int *tab;
	int count;

	count = 0;
	tab = get_flags(format);
	tab[1] == 1 && tab[2] == 1 ? tab[2] = 0 : 0;
	tab[7]--;
	if (tab[1] == 1)
		count = count + cntc('%');
	while (tab[7] > 0)
	{
		tab[2] == 0 ? (count = count + cntc(' ')) : tab[2];
		tab[2] == 1 ? (count = count + cntc('0')) : tab[2];
		tab[7]--;
	}
	if (tab[1] == 0)
		count = count + cntc('%');
	free(tab);
	return (count);
}
