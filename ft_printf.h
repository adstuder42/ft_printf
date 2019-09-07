/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:49:52 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/12 12:46:13 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int			*sub_printf_d0(int *tab, int count);
int			*sub_x0(int *tab, int ct);
int			printf_x0(int *tab, int ct);
int			printf_u0(int *tab, int count);
int			ft_printf(const char *format, ...);
int			cntc(char c);
int			*flag_o(int *tab, char *res);
int			printf_d0(int *tab, int count);
int			*get_flags(const char *str);
int			is_specifier(char c);
int			is_identifier(char c);
size_t		ft_strlen(const char *s);
void		ft_putstr(char const *s);
void		ft_putnbr(int n);
void		ft_putnbrui(unsigned int n);
void		ft_putnbrli(long int n);
void		ft_putnbruli(unsigned long int n);
void		ft_putnbrlli(long long int n);
long int	ft_power(long int n);
void		ft_putchar(char c);
int			disi(int n);
int			printf_o(unsigned int n, const char *format);
int			printf_llo(unsigned long long int n, const char *format);
int			printf_u(unsigned int n, const char *format);
int			printf_lu(unsigned long int n, const char *format);
int			printf_llu(unsigned long long int n, const char *format);
int			ft_intlen(int n);
int			print_octal(char *res, int i, int *tab);
int			printf_x(unsigned int n, const char *format);
int			printf_f(double n, const char *format);
int			printf_lx(unsigned long int n, const char *format);
int			printf_lx2(unsigned long int n, const char *format);
int			printf_llx(unsigned long long int n, const char *format);
int			print_hex(char *res, int i);
int			printf_x2(unsigned int n, const char *format);
int			printf_llx2(unsigned long long int n, const char *format);
int			print_hex2(char *res, int i);
int			printf_d(int n, const char *format);
int			disili(long int n);
int			disilli(long long int n);
int			ft_lintlen(long int n);
int			ft_ulintlen(unsigned long int n);
int			ft_llintlen(long long int n);
int			printf_p(void *p, const char *format);
int			printf_c(int c, const char *format);
int			printf_pc(const char *format);
int			printf_ld(long int n, const char *format);
int			printf_lld(long long int n, const char *format);
int			printf_s(char *str, const char *format);
int			print_null(int *tab);
int			printprec(char *str, int *tab);
char		*hexconv_uli(unsigned long int n);
char		*hexconv_ulli(unsigned long long int n);
int			printf_o0(int *tab);
int			print_width(int *tab, char *ent, int sign);
char		*make_str(char *s);
char		*revstr(char *s);
int			sub_f(int *tab, int sign, char *ent);
char		*make_res(char *ent, char *dec);
int			declen(char *s);
char		*arrondi(char *s, int *tab);
int			print_dec(char *dec, int *tab);
int			print_ent(char *ent);
int			printf_lf(long double n, const char *format);
int			call_c(const char *format, va_list ap);
int			call_p(const char *format, va_list ap);
int			call_s(const char *format, va_list ap);
int			call_f(const char *format, int *tab, va_list ap);
int			call_x2(const char *format, int *tab, va_list ap);
int			call_x(const char *format, int *tab, va_list ap);
int			call_o(const char *format, int *tab, va_list ap);
int			call_u(const char *format, int *tab, va_list ap);
int			call_d(const char *format, int *tab, va_list ap);
int			count_free(int i, int *tab);
int			count_free_f(int i, int *tab, char *s1, char *s2);
int			count_free_x(int i, int *tab, char *res);
char		*ft_strdup(const char *s1);
char		*hexconv(unsigned int n);
int			*flag_x(int *tab, int i);

#endif
