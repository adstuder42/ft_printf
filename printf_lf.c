/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:04:29 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/05 18:30:10 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_entlf(long double n, char *s)
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

char	*get_declf(long double dec, int *tab, char *s)
{
	int				i;
	int				j;
	long double		dectmp;

	j = 0;
	i = tab[9] + 1;
	tab[9] == 0 ? i = 7 : 0;
	dec = dec - (unsigned long long int)dec;
	dectmp = dec;
	while (i > 0)
	{
		dectmp = dectmp * 10;
		s[j] = (unsigned long long int)dectmp + 48;
		dectmp = dectmp - (unsigned long long int)dectmp;
		i--;
		j++;
	}
	s[j] = '\0';
	return (s);
}

int		printf_lf(long double n, const char *format)
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
	ent = revstr(get_entlf(n, make_str(ent)));
	dec = get_declf(n, tab, make_str(dec));
	ent = make_res(ent, dec);
	count = sub_f(tab, sign, ent);
	ent = arrondi(ent, tab);
	count = count + print_ent(ent);
	tab[10] != 1 || tab[9] != 0 ? count = count + print_dec(ent, tab) : 0;
	tab[1] == 1 ? count = count + print_width(tab, ent, sign) : 0;
	return (count_free_f(count, tab, ent, dec) - 1);
}
