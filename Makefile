# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 21:05:33 by almeliky          #+#    #+#              #
#    Updated: 2023/03/09 21:05:39 by almeliky         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRCS		=	ft_printf.c	ft_print_char.c	ft_print_int.c	ft_print_hex.c
			
HEADER		=	./

OBJS		=	$(SRCS:%.c=%.o)

LIBFT_PATH	=	./libft

LIBFT		=	$(LIBFT_PATH)/libft.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -I$(HEADER)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS) $(OBJS_b)

fclean:
	make -C $(LIBFT_PATH) fclean
	rm -rf $(OBJS) $(OBJS_b) $(NAME)

re : fclean all

.PHONY : all clean fclean re libft