NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =		ft_printf.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_putnbr_u_fd.c \
		src/ft_strlcpy.c \
		src/ft_putpointer.c \
		src/ft_hexadecimal.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
