/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:35:17 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/05 18:31:40 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_ent(double n, char *s)
{
	long long int	b;
	int				i;
	int				j;

	i = 0;
	j = 0;
	b = (long long int)n;
	if (b == 0)
		free(s);
	if (b == 0)
		return (ft_strdup("0"));
	while (s[i] != '.' && s[i] != '\0')
		i++;
	s[i] == '\0' ? i = 0 : i;
	s[i] == '.' ? i++ : i;
	while (b != 0)
	{
		j = b % 10;
		b < 0 ? j = -j : j;
		s[i] = j + 48;
		i++;
		b = b / 10;
	}
	s[i] = '\0';
	return (s);
}

char	*get_dec(double dec, int *tab, char *s)
{
	int				i;
	int				j;
	long double		dectmp;

	j = 0;
	i = tab[9] + 1;
	tab[9] == 0 ? i = 7 : 0;
	dec = dec - (long long int)dec;
	dectmp = dec;
	while (i > 0)
	{
		dectmp = dectmp * 10;
		s[j] = (int)dectmp + 48;
		dectmp = dectmp - (int)dectmp;
		i--;
		j++;
	}
	s[j] = '\0';
	return (s);
}

int		print_width(int *tab, char *ent, int sign)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (tab[11] == 1)
	{
		tab[7]--;
		count++;
	}
	if (tab[10] == 1 && tab[9] == 0)
		tab[7] = tab[7] - declen(ent);
	else
		tab[7] = tab[7] - ft_strlen(ent) + 1;
	sign != 0 ? tab[7]-- : 0;
	while (tab[7] > 0)
	{
		tab[2] == 0 ? count = count + cntc(' ') : 0;
		tab[2] == 1 ? count = count + cntc('0') : 0;
		tab[7]--;
	}
	return (count);
}

int		sub_f(int *tab, int sign, char *ent)
{
	int count;

	count = 0;
	sign == -1 && tab[1] == 0 ? count = count + cntc('-') : 0;
	sign == 1 && tab[2] == 1 ? count = count + cntc('+') : 0;
	tab[1] == 0 ? count = count + print_width(tab, ent, sign) : 0;
	sign == -1 && tab[1] == 1 ? count = count + cntc('-') : 0;
	sign == 1 && tab[2] == 0 ? count = count + cntc('+') : 0;
	tab[6] == 4 ? count-- : 0;
	return (count);
}

int		printf_f(double n, const char *format)
{
	int			*tab;
	char		*dec;
	char		*ent;
	int			count;
	int			sign;

	count = 0;
	dec = NULL;
	ent = NULL;
	sign = 0;
	tab = get_flags(format);
	n < 0 && tab[3] == 0 ? sign = -1 : 0;
	n < 0 && tab[3] == 0 ? n = -n : 0;
	tab[3] == 1 && n > 0 ? sign = 1 : 0;
	tab[3] == 1 && n < 0 ? sign = -1 : 0;
	tab[3] == 1 && n < 0 ? n = -n : 0;
	ent = revstr(get_ent(n, make_str(ent)));
	dec = get_dec(n, tab, make_str(dec));
	ent = make_res(ent, dec);
	count = sub_f(tab, sign, ent);
	ent = arrondi(ent, tab);
	count = count + print_ent(ent);
	tab[10] != 1 || tab[9] != 0 ? count = count + print_dec(ent, tab) : 0;
	tab[1] == 1 ? count = count + print_width(tab, ent, sign) : 0;
	return (count_free_f(count, tab, ent, dec));
}
