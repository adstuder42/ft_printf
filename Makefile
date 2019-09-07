# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adstuder <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 15:41:08 by adstuder          #+#    #+#              #
#    Updated: 2019/03/12 13:41:29 by adstuder         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

S_PATH = ./
O_PATH = ./

SRCS += $(S_PATH)ft_intlen.c
SRCS += $(S_PATH)ft_strlen.c
SRCS += $(S_PATH)ft_printf.c
SRCS += $(S_PATH)ft_putchar.c
SRCS += $(S_PATH)ft_putnbr.c
SRCS += $(S_PATH)ft_putstr.c
SRCS += $(S_PATH)ft_strdup.c
SRCS += $(S_PATH)print_hex.c
SRCS += $(S_PATH)print_pc.c
SRCS += $(S_PATH)printf_aux.c
SRCS += $(S_PATH)printf_aux2.c
SRCS += $(S_PATH)printf_c.c
SRCS += $(S_PATH)printf_d.c
SRCS += $(S_PATH)printf_f.c
SRCS += $(S_PATH)printf_f2.c
SRCS += $(S_PATH)printf_f3.c
SRCS += $(S_PATH)printf_ld.c
SRCS += $(S_PATH)printf_lf.c
SRCS += $(S_PATH)printf_lld.c
SRCS += $(S_PATH)printf_llo.c
SRCS += $(S_PATH)printf_llu.c
SRCS += $(S_PATH)printf_llx.c
SRCS += $(S_PATH)printf_llx2.c
SRCS += $(S_PATH)printf_lu.c
SRCS += $(S_PATH)printf_lx.c
SRCS += $(S_PATH)printf_lx2.c
SRCS += $(S_PATH)printf_o.c
SRCS += $(S_PATH)printf_0_aux.c
SRCS += $(S_PATH)printf_0_aux2.c
SRCS += $(S_PATH)printf_p.c
SRCS += $(S_PATH)printf_s.c
SRCS += $(S_PATH)printf_u.c
SRCS += $(S_PATH)printf_x.c
SRCS += $(S_PATH)printf_x2.c
SRCS += $(S_PATH)putnbr_lli.c
SRCS += $(S_PATH)ft_printf_sub1.c
SRCS += $(S_PATH)ft_printf_sub.c
SRCS += $(S_PATH)flag_support.c
SRCS += $(S_PATH)count_free.c

GCC = gcc -c -Wall -Wextra -Werror
OBJ = $(patsubst $(S_PATH)%.c, $(O_PATH)%.o, $(SRCS))

HEADER = ft_printf.h

.PHONY: all clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^

$(OBJ): $(O_PATH)%.o: $(S_PATH)%.c $(HEADER)
	$(GCC) $< -o $@	

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
