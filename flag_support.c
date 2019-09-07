/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:35:25 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/09 18:50:02 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*init_tab(void)
{
	int i;
	int *tab;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * 12)))
		return (NULL);
	while (i < 12)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

int		is_flag(const char *str)
{
	if (str[0] == 'h')
	{
		if (str[1] == 'h')
			return (1);
		else
			return (2);
	}
	else if (str[0] == 'l')
	{
		if (str[1] == 'l')
			return (3);
		else
			return (4);
	}
	else if (str[0] == 'j')
		return (5);
	else if (str[0] == 'z')
		return (6);
	else if (str[0] == 'L')
		return (7);
	return (0);
}

int		*sub_flags(int *tab, const char *str, int i)
{
	while (str[i] == ' ')
	{
		i++;
		tab[0] = 1;
	}
	str[i] == '-' ? tab[1] = 1 : *tab;
	str[i] == '0' && tab[7] == 0 ? tab[2] = 1 : *tab;
	str[i] == '+' ? tab[3] = 1 : *tab;
	if (str[i] == '#')
	{
		tab[2] == 1 ? (tab[2] = 0) : tab[2];
		tab[4] = 1;
		i++;
		if (is_specifier(str[i]) == 1)
			tab[5] = str[i];
		else
			i--;
	}
	tab[11] = i;
	return (tab);
}

int		*sub2_flags(int *tab, const char *str, int i)
{
	if (str[i] == 'h' || str[i] == 'l' || str[i] == 'j' ||
			str[i] == 'z' || str[i] == 'L')
		tab[6] = is_flag(&str[i]);
	tab[6] == 1 || tab[6] == 3 ? i++ : *tab;
	if (str[i] >= '0' && str[i] <= '9')
		tab[7] = tab[7] * 10 + str[i] - '0';
	if (str[i] == '.')
	{
		tab[10] = 1;
		i++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				tab[9] = tab[9] * 10 + str[i] - '0';
				i++;
			}
			i--;
		}
		else
			i--;
	}
	i++;
	tab[11] = i;
	return (tab);
}

int		*get_flags(const char *str)
{
	int i;
	int *tab;

	i = 0;
	tab = init_tab();
	while (is_identifier(str[i]) != 1 && str[i] != '\0')
	{
		tab = sub_flags(tab, str, i);
		i = tab[11];
		tab = sub2_flags(tab, str, i);
		i = tab[11];
	}
	tab[8] = i;
	return (tab);
}
