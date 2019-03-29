# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 19:40:38 by nwispmot          #+#    #+#              #
#    Updated: 2018/12/05 20:05:14 by nwispmot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = *.c

INCLUDES = ./

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
		ar rc $(NAME) *.o
clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: fclean all
