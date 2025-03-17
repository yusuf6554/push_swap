SRCS		= ft_printf.c ft_printf_mods.c ft_printf_mods2.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc
RM			= rm -f
AR			= ar rcs

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
