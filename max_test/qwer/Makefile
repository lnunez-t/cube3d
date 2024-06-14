# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 16:26:06 by lnunez-t          #+#    #+#              #
#    Updated: 2024/06/11 12:10:07 by matorgue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC	= srcs/main.c \
		end/end_game.c \
		srcs/get_next_line.c srcs/get_next_line_utils.c \
		srcs/init/init_data.c srcs/init/init_map.c srcs/init/init_sprites.c srcs/init/render_map.c \
		srcs/init/textures.c srcs/init/init_player_dir.c srcs/init/colors.c srcs/init/valid_textures.c \
		srcs/move/raycaster.c srcs/move/player_move.c srcs/move/handle_player.c srcs/move/check_move.c srcs/move/handle_input.c \
		srcs/parsing/check_path.c srcs/parsing/ft_open.c srcs/parsing/ft_verif_maps.c srcs/parsing/ft_verif_maps2.c srcs/parsing/ft_verif_maps3.c \
		srcs/utils/images.c \

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3 -ftrapv

RM		= rm -f

MLX_DIR = includes/mlx
MLX = libmlx.a 

OBJ_DIR = ./obj
SRC_DIR = ./srcs
INC_DIR = ./includes

LIB = ${INC_DIR}/libft/libft.a

INCLUDES = includes/libft/libft.h includes/cube3d.h

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

%.o:%.c ${INCLUDES}
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

all: ${NAME} ${LIB}

${LIB}:
	@echo "$(GREEN)Compiling libft : $(NC)"
	@make -s -C ${INC_DIR}/libft/ all
	@echo "\033[32m[✓] libft succesfully compiled\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(INCLUDES) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/*/%.c $(INCLUDES) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJ) ${LIB} ${GNL}
		${CC} $(CFLAGS) $(OBJ) -L$(INC_DIR)/libft -lft -o $(NAME) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
		@echo $(NAME) : Created !

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -s -C ${INC_DIR}/libft/ clean

fclean:	clean
	@$(RM) $(NAME)
	@make -s -C ${INC_DIR}/libft/ fclean

re: fclean all

.PHONY: all clean fclean re