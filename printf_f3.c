/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_f3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:51:37 by adstuder          #+#    #+#             */
/*   Updated: 2019/02/05 16:58:16 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_ent(char *ent)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (ent[i] != '.')
	{
		ft_putchar(ent[i]);
		i++;
		count++;
	}
	return (count);
}

int			print_dec(char *dec, int *tab)
{
	int i;
	int count;
	int tmp;

	tmp = tab[9];
	tmp == 0 ? tmp = 6 : 0;
	i = 0;
	count = 0;
	while (dec[i] != '.' && dec[i] != '\0')
		i++;
	i++;
	count = count + cntc('.');
	while (tmp > 0)
	{
		if (tmp == 1 && dec[i + 1] != '\0')
			dec[i + 1] >= '5' ? dec[i]++ : 0;
		count = count + cntc(dec[i]);
		i++;
		tmp--;
	}
	return (count);
}
