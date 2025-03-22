SRC				= main.c checks.c
SRC_DIR			= src

SRCS			= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS			= $(SRCS:.c=.o)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I$(FT_PRINTF_DIR) -I$(LIBFT_DIR)

NAME			= push_swap

FT_PRINTF_DIR	= ft_printf
FT_PRINTF		= $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(FT_PRINTF_DIR) fclean
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re