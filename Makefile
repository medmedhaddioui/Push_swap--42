NAME = push_swap
B_NAME = checker

SRC = push_swap.c utils.c utils1.c actions1.c actions2.c \
	  actions3.c error.c ft_split.c algo1.c utils2.c algo2.c algo3.c \

OBJ = $(SRC:.c=.o)

BSRC = checker_bonus.c get_next_line.c get_next_line_utils.c \
		 utils.c utils1.c  error.c ft_split.c    \

BOBJ = $(BSRC:.c=.o)

all: $(NAME) 



$(NAME) : $(OBJ)
	cc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

bonus : $(B_NAME)

$(B_NAME) :$(BOBJ) 
	cc -Wall -Wextra -Werror $(BOBJ) -o $(B_NAME)

clean:
	rm -rf $(OBJ) $(BOBJ)

fclean: clean
	rm -rf $(NAME) $(B_NAME)

re : fclean all bonus

.PHONY: all bonus clean fclean re

