# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwispmot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 19:40:38 by nwispmot          #+#    #+#              #
#    Updated: 2019/03/02 17:32:35 by nwispmot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
      keys.c \
      coord_n_valid.c \
      bresenham.c \
      print.c \
      rotation.c

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME):
		cc -I /usr/local/include $(SRC) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(INCLUDES)

clean:
		rm -f *.o    

fclean: clean
		rm -f $(NAME)

re: fclean all
