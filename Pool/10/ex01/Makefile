NAME = ft_cat
SRC = ft_cat.c
OBJ = ${SRC:.c=.o}
GCC = gcc
FLAGS = -Wall -Wextra -Werror
OPTIONS = -o ${NAME}

all: ${NAME}

${NAME}:
	${GCC} ${FLAGS} ${SRC} ${OPTIONS}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

.PHONY: all clean fclean
