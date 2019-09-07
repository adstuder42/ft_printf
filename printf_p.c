/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:34:48 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/05 17:59:26 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_hexp(char *res, int i)
{
	int count;

	count = 2;
	i--;
	ft_putstr("0x");
	i == -1 ? count = count + cntc('0') : 0;
	while (i >= 0)
	{
		if (res[i] >= 40 && res[i] <= 57)
			ft_putchar(res[i]);
		if (res[i] == 58)
			ft_putchar('a');
		if (res[i] == 59)
			ft_putchar('b');
		if (res[i] == 60)
			ft_putchar('c');
		if (res[i] == 61)
			ft_putchar('d');
		if (res[i] == 62)
			ft_putchar('e');
		res[i] == 63 ? ft_putchar('f') : 0;
		count++;
		i--;
	}
	return (count);
}

char		*hexconv_li(long int n)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	res = make_str(res);
	while (n > 0)
	{
		res[i] = (n % 16) + 48;
		n = n / 16;
		i++;
	}
	res[i] = n % 16;
	res[i + 1] = '\0';
	return (res);
}

int			printf_p0(int *tab, int i)
{
	int count;

	count = 0;
	tab[2] == 1 && tab[1] == 1 ? tab[2] = 0 : 0;
	tab[7] = tab[7] - i;
	tab[1] == 1 && tab[10] == 1 && tab[9] <= 0 ? ft_putstr("0x") : 0;
	tab[10] == 1 && tab[9] <= 0 ? count = count + 2 : 0;
	tab[1] == 1 && (tab[10] == 0 || tab[9] > 0) ?
		count = count + print_hexp("", 0) : 0;
	while (tab[7] > 0)
	{
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[7]--;
	}
	tab[1] == 0 && tab[10] == 1 && tab[9] <= 0 ? ft_putstr("0x") : 0;
	tab[1] == 0 && (tab[10] == 0 || tab[9] > 0) ?
		count = count + print_hexp("", 0) : 0;
	while (tab[9] - 1 > 0)
	{
		count = count + cntc('0');
		tab[9]--;
	}
	return (count);
}

int			printf_p(void *p, const char *format)
{
	int			i;
	char		*res;
	int			count;
	int			*tab;
	long int	n;

	count = 0;
	n = (long int)p;
	tab = get_flags(format);
	res = hexconv_li(n);
	i = ft_strlen(res);
	if (p == 0 || p == NULL)
		return (count_free_x(printf_p0(tab, 3), tab, res));
	tab[1] == 1 && tab[2] == 1 ? tab[2] = 0 : 0;
	tab[7] = tab[7] - i - 2;
	tab[1] == 1 ? count = count + print_hexp(res, i) : 0;
	while (tab[7] > 0)
	{
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[7]--;
	}
	tab[1] == 0 ? count = count + print_hexp(res, i) : 0;
	return (count_free_x(count, tab, res));
}
