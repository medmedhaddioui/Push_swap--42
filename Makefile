NAME = push_swap

SRC = push_swap.c
OBJS = $(SRC:.c=.o)

LIB = libft/libft.a
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB):
	cd libft && make

clean:
	$(RM) $(OBJS)
	cd libft && make clean

fclean: clean
	$(RM) $(NAME)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
