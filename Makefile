NAME = push_swap
LIB = libft/libft.a
RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	cd libft && make
	$(CC) $(CFLAGS) libft/libft.a main.c  -o $(NAME)

clean : 
	$(RM) libft/*.o

fclean : clean
	$(RM) $(LIB) $(NAME)

re: fclean all

.PHONY: all clean fclean re
