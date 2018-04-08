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
FILES = $(wildcard *.c)

OBJECTS = $(FILES:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(FILES) -I ./includes
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
