# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 21:08:20 by nwispmot          #+#    #+#              #
#    Updated: 2019/03/29 21:08:25 by nwispmot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

OBJ = $(patsubst %.c, %.o, $(SRC))

SRC = main.c \
      keys.c \
      coord_n_valid.c \
      bresenham.c \
      print.c \
      rotation.c \
      move.c \
      valid.c \
      mem.c

INC = fdf.h

LIB = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(FLAGS) -o $(NAME) $^ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB) -I $(INC) 

%.o:%.c
	gcc $(FLAGS) -c $^ -o $@ -I $(INC)

run: 
	gcc -g $(SRC) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB) -I $(INC) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./libft 
	/bin/rm -f $(NAME)

re: fclean all
