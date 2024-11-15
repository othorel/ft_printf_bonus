SRCS =  ft_printf.c  \
		ft_putchar.c \
		ft_putstr.c  \
		ft_putnbr.c  \
		ft_puthexa.c \
		ft_putptr.c  \
		ft_utils.c   \
		ft_putunsigned.c  \
		
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC   = gcc -Wall -Wextra -Werror

%.o: %.c ft_printf.h
			${CC} -I. -c $< -o ${<:.c=.o}

all:	${NAME}

$(NAME):	${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

bonus:		${OBJS} ft_printf.h
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
