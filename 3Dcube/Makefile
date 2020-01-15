# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wbarendr <wbarendr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 14:53:04 by wbarendr       #+#    #+#                 #
#    Updated: 2020/01/15 21:42:53 by wbarendr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS = main_test_valic check_if_valid 3dcube utils ft_atoi

CFILES  = $(SRCS:%=%.c)

all:
	gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework \
	OpenGL -framework AppKit $(CFILES)

clean:
	rm -f a.out

fclean: clean

re: flcean all
