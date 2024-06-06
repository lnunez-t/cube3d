# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matorgue <warthog2603@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 17:14:08 by matorgue          #+#    #+#              #
#    Updated: 2024/06/06 12:48:36 by matorgue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test

# Compiler and flags
CC = cc
CFLAGS = -Werror -Wall -Wextra

# Source files and object files
SRC = main.c\
	  ft_init.c\
	  ft_end.c\
	  ft_verif_maps.c\
	  ft_verif_maps2.c\
	  ft_open.c
OBJ = ${SRC:.c=.o}

# Path to libft and includes (assuming libft.a is in the same directory)
LIBFT = ./libft/libft.a
INCLUDES = -I ./includes  # Adjust the path to your includes if necessary

# Rule to compile .c files to .o files
%.o: %.c
	${CC} -g3 -c -o $@ $< ${INCLUDES}

# Rule to create the final executable
${NAME}: ${OBJ} ${LIBFT}
	${CC} -o ${NAME} ${OBJ} ${CFLAGS} ${LIBFT}

# Rule to compile all files
all: ${NAME}

# Rule to clean object files
clean:
	rm -f ${OBJ}

# Rule to clean object files and executable
fclean: clean
	rm -f ${NAME}

# Rule to recompile everything
re: fclean all
