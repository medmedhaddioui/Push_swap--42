NAME = push_swap
NAME_BONUS = checker

SRC =	push_swap.c utils.c utils1.c actions1.c actions2.c \
	 	actions3.c error.c ft_split.c algo1.c utils2.c algo2.c algo3.c \

SRC_BONUS =	checker_bonus.c get_next_line.c get_next_line_utils.c \
	   bonus_utils.c utils.c utils1.c actions1.c actions2.c \
		push.c error.c ft_split.c algo1.c utils2.c algo2.c algo3.c
		
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME): $(SRC)
	cc -Wextra -Werror -Wall $(SRC) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(SRC_BONUS)
	cc -Wall -Wextra -Werror $(SRC_BONUS) -o $(NAME_BONUS)

clean:
	rm -rf $(OBJECT) $(OBJECT_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all bonus

.PHONY: all bonus clean fclean re