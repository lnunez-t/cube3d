LIB = get_next_line.c get_next_line_utils.c

SRCS = ${LIB}

OBJS = ${SRCS:.c=.o}

INCLUDES = get_next_line.h

NAME = get_next_line.a

CC = cc 

CFLAGS = -Wall -Werror -Wextra -g3

.c.o :
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${INCLUDES}
				ar -rsc ${NAME} ${OBJS}

bonus : ${OBJSALL}
				ar -rsc ${NAME} ${OBJSALL}

all:	${NAME}

clean:
				rm -f ${OBJSALL}

fclean: clean;
				rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re