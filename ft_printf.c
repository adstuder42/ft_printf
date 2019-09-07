/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:40:01 by adstuder          #+#    #+#             */
/*   Updated: 2019/02/24 16:27:46 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_pc(const char *format)
{
	int count;

	count = 0;
	count = count + printf_pc(format);
	return (count);
}

int		call_list(const char *format, int *tab, va_list ap, char c)
{
	int count;

	count = 0;
	if (c == 's')
		count = count + call_s(format, ap);
	if (c == 'd' || c == 'i')
		count = count + call_d(format, tab, ap);
	if (c == 'u' || c == 'U')
		count = count + call_u(format, tab, ap);
	if (c == 'o' || c == 'O')
		count = count + call_o(format, tab, ap);
	if (c == 'x')
		count = count + call_x(format, tab, ap);
	if (c == 'X')
		count = count + call_x2(format, tab, ap);
	if (c == 'f' || c == 'F')
		count = count + call_f(format, tab, ap);
	if (c == 'p')
		count = count + call_p(format, ap);
	if (c == 'c')
		count = count + call_c(format, ap);
	if (c == '%')
		count = count + call_pc(format);
	return (count_free(count, tab));
}

int		isnt_identifier(const char *format, int ct, int i, int j)
{
	ft_putstr(&format[i + j]);
	ct = ct + ft_strlen(&format[i + j]);
	i = i + ft_strlen(&format[i + j]);
	return (ct);
}

int		sub_ft_printf(const char *format, va_list ap, int **tab, int ct)
{
	int j;
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		j = 0;
		if (format[i] == '%')
		{
			if (format[++i] == '\0')
				return (ct);
			*tab = get_flags(&format[i]);
			while (is_identifier(format[i + j]) == 0 && format[i + j] != '\0')
				j++;
			if (is_identifier(format[i + j]) == 1)
				ct = ct + call_list(&format[i], *tab, ap, format[i + j]);
			else if (is_identifier(format[i + j] == -1))
				return (isnt_identifier(format, count_free(ct, *tab), i, j));
		}
		else
			ct = ct + cntc(format[i]);
		i = i + j + 1;
	}
	return (ct);
}

int		ft_printf(const char *format, ...)
{
	int		*tab;
	va_list	ap;
	int		ct;

	tab = NULL;
	ct = 0;
	va_start(ap, format);
	ct = sub_ft_printf(format, ap, &tab, ct);
	return (ct);
}
