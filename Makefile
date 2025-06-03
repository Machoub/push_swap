# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machouba <machouba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 12:16:13 by machouba          #+#    #+#              #
#    Updated: 2024/04/05 17:50:58 by machouba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIBFT_PATH	=	./libft

LIBFT	=	$(LIBFT_PATH)/libft.a

CC = cc

CFLAGS	= -Wall -Wextra -Werror -I$(LIBFT)

RM	=	rm -f

AR	=	ar -rcs

HEADER = push_swap.h

SOURCES = \
	ft_errors.c \
	init_a_to_b.c \
	init_b_to_a.c \
	lst_utils.c \
	push_swap.c \
	push.c \
	rev_rotate.c \
	rotate.c \
	sort_stack.c \
	sort_stack2.c \
	sort_three.c \
	stack_init.c \
	swap.c \
	split.c
	
OBJECTS	= $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT) $(NAME)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJECTS)

fclean:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re