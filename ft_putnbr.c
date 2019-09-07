/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:16:26 by adstuder          #+#    #+#             */
/*   Updated: 2019/01/24 17:40:29 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int			ft_power(long int n)
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

unsigned long int	ft_poweruli(unsigned long int n)
{
	int					i;
	unsigned long int	j;

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

void				ft_putnbr(int n)
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

void				ft_putnbrli(long int n)
{
	long int			j;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	j = ft_power(n);
	while (j > 0)
	{
		ft_putchar((n / j) + 48);
		n = n % j;
		j = j / 10;
	}
}

void				ft_putnbruli(unsigned long int n)
{
	unsigned long int			j;

	j = ft_poweruli(n);
	while (j > 0)
	{
		ft_putchar((n / j) + 48);
		n = n % j;
		j = j / 10;
	}
}
