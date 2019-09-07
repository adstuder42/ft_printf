/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_f2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:44:42 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/12 13:09:47 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*make_str(char *s)
{
	int i;

	i = 0;
	if (!(s = malloc(sizeof(char) * 1000 + 1)))
		return (0);
	s[1000] = '\0';
	while (s[i] != '\0')
	{
		s[i] = 'x';
		i++;
	}
	return (s);
}

char		*revstr(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (s[j] != '\0')
		j++;
	j--;
	while (j > i)
	{
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i++;
		j--;
	}
	return (s);
}

int			declen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '.')
		i++;
	return (i);
}

char		*arrondi(char *s, int *tab)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i--;
	if (s[i] > 53)
	{
		s[i] = '0';
		i--;
		s[i] == '.' ? i-- : 0;
		s[i]++;
		s[i] == 58 ? s[i] = 48 : 0;
		while (s[i] == 48)
		{
			i == 0 ? ft_putchar('1') : 0;
			i == 0 ? tab[11] = 1 : 0;
			i--;
			s[i] == '.' ? i-- : 0;
			s[i]++;
			s[i] == 58 ? s[i] = 48 : 0;
		}
	}
	return (s);
}

char		*make_res(char *ent, char *dec)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = NULL;
	s = make_str(s);
	while (ent[i] != '\0')
	{
		s[i] = ent[i];
		i++;
	}
	s[i] = '.';
	i++;
	while (dec[j] != '\0')
	{
		s[i + j] = dec[j];
		j++;
	}
	s[i + j] = '\0';
	free(ent);
	return (s);
}
