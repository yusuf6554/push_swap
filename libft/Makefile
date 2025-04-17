SRCS		= ft_split.c ft_atoi.c

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		$(NAME)

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re