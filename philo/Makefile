CC= cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3
NAME= philo
INCLUDES= philo.h
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I./ -o $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re