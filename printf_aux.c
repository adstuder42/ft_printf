/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:22:08 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/12 13:06:22 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_identifier(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
			c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
			c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%' ||
			c == 'f' || c == 'F')
		return (1);
	else if (c == '+' || c == '-' || c == '#' || c == '.' ||
			(c <= '9' && c >= '0') || c == ' ' || c == 'h' || c == 'l' ||
			c == 'j' || c == 'z' || c == 'L')
		return (0);
	else
		return (-1);
}

int		is_specifier(char c)
{
	if (c == 'o' || c == 'x' || c == 'X' || c == 'e' || c == 'E' ||
			c == 'f' || c == 'g' || c == 'G')
		return (1);
	else
		return (0);
}

int		print_null10(int *tab, char *nul)
{
	int count;
	int i;

	count = 0;
	i = 0;
	tab[7] < tab[9] ? tab[7] = 0 : tab[7];
	while (tab[7] > 0 && tab[1] == 0)
	{
		count = count + cntc(' ');
		tab[7]--;
	}
	while (tab[9] > 0)
	{
		write(1, &nul[i], 1);
		i++;
		tab[9]--;
		count++;
	}
	while (tab[7] > 0)
	{
		count = count + cntc(' ');
		tab[7]--;
	}
	return (count_free(count, tab));
}

int		print_null(int *tab)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (tab[10] == 1)
		return (print_null10(tab, "(null)"));
	tab[2] == 1 ? ft_putstr("(null)") : 0;
	tab[7] < 6 && tab[10] == 0 ? count = 6 : tab[7];
	tab[7] < 6 && tab[10] == 0 ? tab[7] = 0 : tab[7];
	tab[7] >= 6 ? count = count + 6 : tab[7];
	tab[7] >= 6 ? tab[7] = tab[7] - 6 : tab[7];
	if (tab[1] == 1)
		ft_putstr("(null)");
	while (tab[7] > 0)
	{
		count = count + cntc(' ');
		tab[7]--;
	}
	tab[1] == 0 ? ft_putstr("(null)") : tab[10];
	return (count_free(count, tab));
}

int		printprec(char *str, int *tab)
{
	int i;

	i = 0;
	if (tab[10] == 1)
	{
		while (tab[9] > 0 && str[i] != '\0')
		{
			ft_putchar(str[i]);
			tab[9]--;
			i++;
		}
		return (i);
	}
	else
		ft_putstr(str);
	return (ft_strlen(str));
}
