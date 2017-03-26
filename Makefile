# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaragul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/28 18:18:25 by egaragul          #+#    #+#              #
#    Updated: 2017/03/05 22:56:57 by egaragul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 
NAME = libftprintf.a

SRC = ft_begin.c\
	  ft_check_for_type.c\
	  ft_fill_flags.c\
	  ft_fill_modificators.c\
	  ft_fill_prec_wid.c\
	  ft_for_did_digits_wid.c\
	  ft_init_struct.c\
	  ft_itoa_base.c\
	  ft_itoa_base_unsigned.c\
	  ft_print_did_digits.c\
	  ft_print_functions.c\
	  ft_print_out.c\
	  ft_print_out_string.c\
	  ft_print_oux_digits.c\
	  ft_print_p_type.c\
	  ft_print_ub.c\
	  ft_printf.c\
	  ft_rec_unb_type.c\
	  ft_for_perc_rec_only.c\
	  ft_strdup_wint.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_strlen.c\
	  ft_strsub.c\
	  ft_tolower.c\
	  ft_strnew.c\
	  ft_strchr.c\
	  ft_strcmp.c\
	  ft_memset.c\
	  ft_strstr.c\
	  ft_strdup.c\
	  ft_atoi.c\
	  ft_strrchr.c\
	  ft_what_type_print.c
GG = $(SRC:.c=.o)
HEAD = ft_printf.h
FLAG = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(GG)
	ar rc $(NAME) $(GG)
	ranlib $(NAME)

%.o: %c $(HEAD)
	gcc -o $(NAME) $(FLAG) $@ $<

clean:
	rm -f $(GG)

fclean: clean
	rm -f $(NAME)

re: fclean all
