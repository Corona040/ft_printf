NAME = libftprintf.a

OUT = test.out

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBS = -I./libft

SRCS =	ft_printf.c				\
		utils.c					\
		utils2.c				\
		utils3.c				\
		libft/ft_strlen.c		\
		libft/ft_strncmp.c		\
		libft/ft_putchar_fd.c	\
		libft/ft_putstr_fd.c	\
		libft/ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	@make -C libft

$(NAME): makelib $(OBJS)
	ar rcs $@ $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(LIBS) $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OUT): $(SRCS) $(BONUS_SRCS)
	$(CC) $(SRCS) $(BONUS_SRCS) $(LIBS) -o $@

.PHONY: all bonus clean fclean re
