/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 13:34:13 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/12 13:34:19 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_d(const char *format, int *tab, va_list ap)
{
	int count;

	count = 0;
	if (tab[6] != 2 && tab[6] != 1 && tab[6] != 4 && tab[6] != 3 &&
			tab[6] != 5 && tab[6] != 6)
		count = count + printf_d(va_arg(ap, int), format);
	if (tab[6] == 2)
		count = count + printf_d((short int)va_arg(ap, int), format);
	if (tab[6] == 4)
		count = count + printf_ld(va_arg(ap, long int), format);
	if (tab[6] == 3)
		count = count + printf_lld(va_arg(ap, long long int), format);
	if (tab[6] == 1)
		count = count + printf_d((signed char)va_arg(ap, int), format);
	return (count);
}

int		call_u(const char *format, int *tab, va_list ap)
{
	int count;

	count = 0;
	if (tab[6] != 1 && tab[6] != 4 && tab[6] != 3 && tab[6] != 5 &&
			tab[6] != 2 && tab[6] != 6)
		count = count + printf_u(va_arg(ap, unsigned int), format);
	if (tab[6] == 4)
		count = count + printf_lu(va_arg(ap, unsigned long int), format);
	if (tab[6] == 3)
		count = count + printf_llu(va_arg(ap, unsigned long long int), format);
	if (tab[6] == 2)
		count = count + printf_u((unsigned short)va_arg(ap, long), format);
	if (tab[6] == 1)
		count = count + printf_u((unsigned char)va_arg(ap, int), format);
	return (count);
}

int		call_o(const char *format, int *tab, va_list ap)
{
	int count;

	count = 0;
	if (tab[6] != 1 && tab[6] != 3 && tab[6] != 6 && tab[6] != 5 &&
		tab[6] != 4 && tab[6] != 2)
		count = count + printf_o(va_arg(ap, unsigned int), format);
	if (tab[6] == 1)
		count = count + printf_o((unsigned char)va_arg(ap, int), format);
	if (tab[6] == 2)
		count = count + printf_o((unsigned short)va_arg(ap, int), format);
	if (tab[6] == 3 || tab[6] == 4)
		count = count + printf_llo(va_arg(ap, unsigned long long int), format);
	return (count);
}

int		call_x(const char *format, int *tab, va_list ap)
{
	int count;

	count = 0;
	if (tab[6] != 1 && tab[6] != 4 && tab[6] != 5 && tab[6] != 3 && tab[6] != 6)
		count = count + printf_x(va_arg(ap, unsigned int), format);
	if (tab[6] == 1)
		count = count + printf_x((unsigned char)va_arg(ap, int), format);
	if (tab[6] == 3)
		count = count + printf_llx(va_arg(ap, unsigned long long int), format);
	if (tab[6] == 4)
		count = count + printf_lx(va_arg(ap, unsigned long int), format);
	return (count);
}

int		call_x2(const char *format, int *tab, va_list ap)
{
	int count;

	count = 0;
	if (tab[6] == 1)
		count = count + printf_x2((unsigned char)va_arg(ap, int), format);
	if (tab[6] == 4)
		count = count + printf_lx2(va_arg(ap, unsigned long int), format);
	if (tab[6] != 1 && tab[6] != 3 && tab[6] != 5 && tab[6] != 4 && tab[6] != 6)
		count = count + printf_x2(va_arg(ap, unsigned int), format);
	if (tab[6] == 3)
		count = count + printf_llx2(va_arg(ap, unsigned long long), format);
	return (count);
}
