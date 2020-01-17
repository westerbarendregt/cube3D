# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wbarendr <wbarendr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 14:53:04 by wbarendr       #+#    #+#                 #
#    Updated: 2020/01/17 16:52:37 by wbarendr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS =	main_test_valic check_if_valid dcube utils put_map_to_window \
		free_functions get_data_input get_data_strings get_data_integers

CFILES  = $(SRCS:%=%.c)

all:
	gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework \
	OpenGL -framework AppKit $(CFILES)

clean:
	rm -f a.out

fclean: clean

re: flcean all
