NAME = push_swap

SRC = push_swap.c utils.c utils1.c actions1.c actions2.c \
	  actions3.c
	

OBJ =  $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	
	gcc -Wall -Wextra -Werror -fsanitize=address $(SRC) -o $(NAME) 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all