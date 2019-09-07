/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:20:54 by adstuder          #+#    #+#             */
/*   Updated: 2019/02/27 12:44:24 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		count_free(int i, int *tab)
{
	tab == NULL ? 0 : free(tab);
	return (i);
}

int		count_free_f(int i, int *tab, char *s1, char *s2)
{
	tab == NULL ? 0 : free(tab);
	free(s1);
	free(s2);
	return (i);
}

int		count_free_x(int i, int *tab, char *res)
{
	tab == NULL ? 0 : free(tab);
	free(res);
	return (i);
}
