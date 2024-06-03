# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 16:26:06 by lnunez-t          #+#    #+#              #
#    Updated: 2024/05/15 16:44:25 by lnunez-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cube3d

SRC_DIR = ./srcs
OBJ_DIR = ./objs
INC_DIR = ./includes

INCLUDES = includes/cube3d.h includes/libft/libft.h includes/libft/libft.h \
			includes/get_next_line.h

SRCS = main.c\

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
	
CC = cc

CFLAGS =  -g3  -Wextra -Werror -Wall
MLX_FLAGS = -L mlx -lmlx -lXext -lX11 -lm

LIB = ${INC_DIR}/libft/libft.a
MLX = ${INC_DIR}/mlx/libmlx.a
GNL = ${INC_DIR}/mlx/get_next_line.a

%.o:%.c ${INCLUDES}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME} ${LIB} ${MLX} ${GNL}

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

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(INCLUDES) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/*/%.c $(INCLUDES) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJ) ${LIB} ${MLX} ${GNL}
	@$(CC) $(MLX_FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[32m[✓] cube3d succesfully compiled\033[0m"

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -s -C ${INC_DIR}/libft/ clean
	@make -s -C ${INC_DIR}/get_next_line/ clean

fclean: clean
	@$(RM) $(NAME)
	@make -s -C ${INC_DIR}/libft/ fclean
	@make -s -C ${INC_DIR}/get_next_line/ fclean

re: fclean all

.PHONY: all clean fclean re