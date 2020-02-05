# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 13:10:21 by vdelsie           #+#    #+#              #
#    Updated: 2020/02/05 21:06:01 by vdelsie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = vdelsie.filler
#VIS = vdelsie.visualizer

CFLAGS = -Wall -Werror -Wextra -g

INCLUDES = includes
LIBFT = libft
#MLX = minilibx

SRC_CFILES = border_calc.c\
			 border_check.c\
			 border_clear.c\
			 debug_files_others_on.c\
			 debug_files_stratmap_on.c\
			 delete_and_clear.c\
			 strat_argument.c\
			 heat_calc_sub_fct.c\
			 heat_calc_main.c\
			 strat_calc.c\
			 first_init.c\
			 put_piece.c\
			 get_data.c\
			 tools_strat.c\
			 tools_player.c\
			 tools_basics.c\
			 tools_read.c\
			 main.c

SRC_OFILES = $(SRC_CFILES:.c=.o)

#VIS_CFILES = color.c\
			 image.c\
			 key_hooks.c\
			 render.c

#VIS_OFILES = $(VIS_CFILES:.c=.o)

all: $(NAME) #$(VIS) 

$(NAME):
	@echo "\x1b[1m\nBuilding $(LIBFT) library...\x1b[0m"
	make -C $(LIBFT)
	@echo "\x1b[1m\nBuilding $(NAME)...\x1b[0m"
	$(CC) $(CFLAGS) -c $(addprefix SRC/, $(SRC_CFILES)) -I$(INCLUDES)
	$(CC) -o $(NAME) $(SRC_OFILES) -L$(LIBFT) -lft

#$(VIS):
	#@echo "\x1b[1m\nBuilding $(MLX) library...\x1b[0m"
	#make -C $(MLX)
	#@echo "\x1b[1m\nBuilding $(VIS)...\x1b[0m"
	#$(CC) $(CFLAGS) -c $(addprefix VIS/, $(VIS_CFILES)) -I$(INCLUDE)
	#$(CC) -o $(VIS) $(VIS_OFILES) -L$(LIBFT) -lft -L$(MLX) -lmlx\
		-framework OpenGL -framework AppKit

clean:
	@echo "\x1b[1m\nCleaning...\x1b[0m"
	make -C $(LIBFT) clean
	#make -C $(MLX) clean
	#/bin/rm -f $(VIS_OFILES)
	/bin/rm -f $(SRC_OFILES)

fclean: clean
	/bin/rm -f $(LIBFT)/libft.a
	#/bin/rm -f $(MLX)/libmlx.a
	#/bin/rm -f $(VIS)/vdelsie.visualizer.a
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
