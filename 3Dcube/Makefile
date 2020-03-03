# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wbarendr <wbarendr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/08 14:53:04 by wbarendr       #+#    #+#                 #
#    Updated: 2020/03/02 17:06:10 by wbarendr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS =	main check_if_valid dcube utils put_map_to_window2 \
		free_functions get_data_input get_data_strings get_data_integers \
		pov_walker2 mini_map textures move_wasd find_wall spritehit_x \
		initialize utils2 find_wall2 make_bmp find_values

B1 = ./bonus_files/bonus_functions_bonus.c ./bonus_files/mini_map2_bonus.c

CFILES  = $(SRCS:%=%.c)
CFILE3 = $(addprefix mandatory_files/,$(CFILES))
BFILES = $(SRCS:%=%_bonus.c)
BFILE3 = $(addprefix bonus_files/,$(BFILES))

all: $(NAME)

$(NAME):
	gcc -Ofast -march=native -Wall -Wextra -Werror -I minilibx -L minilibx \
	-lmlx -framework OpenGL -framework AppKit -o $(NAME) $(CFILE3)
	./$(NAME)
bonus:
	gcc -Ofast -march=native -Wall -Wextra -Werror -I minilibx -L minilibx \
	-lmlx -framework OpenGL -framework AppKit -o $(NAME) $(BFILE3) $(B1)
	./$(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
