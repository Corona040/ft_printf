NAME = libftprintf.a

OUT = test.out

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS = -I./libft -L./libft -lft

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $(LIBS) $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OUT): $(SRCS) $(BONUS_SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS) $(BONUS_SRCS) $(LIBS)

test: $(OUT)

tclean:
	rm -f $(OUT)

.PHONY: all bonus clean fclean re test tclean