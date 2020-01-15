# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wbarendr <wbarendr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 14:53:04 by wbarendr       #+#    #+#                 #
#    Updated: 2020/01/15 12:57:42 by wbarendr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework \
	OpenGL -framework AppKit main4.c
	./a.out
clean:
	rm -f a.out

fclean: clean

re: flcean all
