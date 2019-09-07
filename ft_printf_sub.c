/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:33:55 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/12 13:34:00 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_f(const char *format, int *tab, va_list ap)
{
	int count;

	count = 0;
	if (tab[6] != 7)
		count = count + printf_f(va_arg(ap, double), format);
	if (tab[6] == 7)
		count = count + printf_lf(va_arg(ap, long double), format);
	return (count);
}

int		call_s(const char *format, va_list ap)
{
	int count;

	count = 0;
	count = count + printf_s(va_arg(ap, char *), format);
	return (count);
}

int		call_p(const char *format, va_list ap)
{
	int count;

	count = 0;
	count = count + printf_p(va_arg(ap, void*), format);
	return (count);
}

int		call_c(const char *format, va_list ap)
{
	int count;

	count = 0;
	count = count + printf_c(va_arg(ap, int), format);
	return (count);
}
