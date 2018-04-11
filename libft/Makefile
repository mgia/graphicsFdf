# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 17:49:03 by mtan              #+#    #+#              #
#    Updated: 2018/03/08 10:29:52 by mtan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)
INC = includes/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I $(INC) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
