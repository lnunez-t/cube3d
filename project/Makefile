# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 16:26:06 by lnunez-t          #+#    #+#              #
#    Updated: 2024/06/03 16:34:31 by matorgue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_DIR = ./srcs
OBJ_DIR = ./objs
INC_DIR = ./includes

INCLUDES = $(INC_DIR)/cube3d.h $(INC_DIR)/libft/libft.h $(INC_DIR)/libft/libft.h \
            $(INC_DIR)/get_next_line.h

SRCS = $(SRC_DIR)/main.c

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC = cc

CFLAGS =  -g3  -Wextra -Werror -Wall
MLX_FLAGS = -L mlx -lmlx -lXext -lX11 -lm

LIB = ${INC_DIR}/libft/libft.a
MLX = ${INC_DIR}/mlx/libmlx.a
GNL = ${INC_DIR}/mlx/get_next_line.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) | $(OBJ_DIR)
    $(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
    @mkdir -p $(OBJ_DIR)

all: ${NAME}

$(NAME): $(OBJ) ${LIB} ${MLX} ${GNL}
    $(CC) $(MLX_FLAGS) $(OBJ) -o $(NAME)
    @echo "\033[32m[✓] $(NAME) successfully compiled\033[0m"

${LIB}:
    @echo "$(GREEN)Compiling libft : $(NC)"
    @make -s -C ${INC_DIR}/libft/ all
    @echo "\033[32m[✓] libft succesfully compiled\033[0m"

${MLX}:
    @echo "$(GREEN)Compiling minilibx : $(NC)"
    @make -s -C ${INC_DIR}/mlx/ all
    @echo "\033[32m[✓] minilibx succesfully compiled\033[0m"

${GNL}:
    @echo "$(GREEN)Compiling get_next_line : $(NC)"
    @make -s -C ${INC_DIR}/get_next_line/ all
    @echo "\033[32m[✓] get_next_line succesfully compiled\033[0m"

clean:
    @rm -rf $(OBJ_DIR)
    @make -s -C ${INC_DIR}/libft/ clean
    @make -s -C ${INC_DIR}/get_next_line/ clean

fclean: clean
    @rm -f $(NAME)
    @make -s -C ${INC_DIR}/libft/ fclean
    @make -s -C ${INC_DIR}/get_next_line/ fclean

re: fclean all

.PHONY: all clean fclean re