/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:05:21 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/11 15:33:46 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_octal(char *res, int i, int *tab)
{
	int count;

	count = 0;
	i--;
	tab[0] = tab[0];
	if (tab[4] == 1)
	{
		write(1, "0", 1);
		count++;
	}
	while (i >= 0)
	{
		ft_putchar(res[i]);
		count++;
		i--;
	}
	return (count);
}

char	*octoconv_ui(unsigned int n)
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

int		*flag_o(int *tab, char *res)
{
	tab[1] == 1 ? tab[2] = 0 : tab[2];
	if (tab[9] >= tab[7])
	{
		tab[7] = 0;
		tab[9] = tab[9] - ft_strlen(res);
	}
	else if (tab[7] > tab[9])
	{
		tab[9] <= (int)ft_strlen(res) ? tab[9] = 0 : 0;
		tab[9] > (int)ft_strlen(res) ?
			tab[9] = tab[9] - (int)ft_strlen(res) : 0;
		tab[7] = tab[7] - (tab[9] + (int)ft_strlen(res));
	}
	tab[4] == 1 ? tab[7]-- : tab[7];
	return (tab);
}

int		*sub_o(int *tab, int count, int i, char *res)
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

int		printf_o(unsigned int n, const char *format)
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
	res = octoconv_ui(n);
	i = ft_strlen(res);
	tab = flag_o(tab, res);
	while (tab[7] > 0 && tab[1] == 0)
	{
		tab[2] == 1 ? 0 : (count = count + cntc(' '));
		tab[2] == 1 ? (count = count + cntc('0')) : 0;
		tab[7]--;
	}
	tab[4] == 1 && tab[9] > 0 ? tab[9]-- : tab[9];
	tab = sub_o(tab, count, i, res);
	count = tab[11];
	free(res);
	free(tab);
	return (count);
}
