NAME = libftprintf.a

OUT = test.out

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -Ilibft

SRCS =	ft_printf.c				\
		utils.c					\
		utils2.c				\
		utils3.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	@make -C libft

$(NAME): makelib $(OBJS)
	cp libft/libft.a $@
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all

$(OUT): $(SRCS) $(BONUS_SRCS)
	$(CC) $(SRCS) $(BONUS_SRCS) $(LIBS) -o $@

.PHONY: all bonus clean fclean re
