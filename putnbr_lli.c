/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_lli.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:15:11 by adstuder          #+#    #+#             */
/*   Updated: 2019/01/24 16:56:04 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long int		ft_powerlli(long long int n)
{
	int			i;
	long int	j;

	i = 1;
	j = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	while (i > 1)
	{
		j = j * 10;
		i--;
	}
	return (j);
}

void				ft_putnbrlli(long long int n)
{
	long int	j;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	j = ft_powerlli(n);
	while (j > 0)
	{
		ft_putchar((n / j) + 48);
		n = n % j;
		j = j / 10;
	}
}

void				ft_putnbrui(unsigned int n)
{
	long int	j;
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	j = ft_power(nb);
	while (j > 0)
	{
		ft_putchar((nb / j) + 48);
		nb = nb % j;
		j = j / 10;
	}
}

void				ft_putnbruimax(uintmax_t n)
{
	long int	j;
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	j = ft_power(nb);
	while (j > 0)
	{
		ft_putchar((nb / j) + 48);
		nb = nb % j;
		j = j / 10;
	}
}
