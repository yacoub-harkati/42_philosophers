CC= cc
CFLAGS= -Wall -Wextra -Werror #-fsanitize=thread -g3
NAME= philo
INCLUDES= philo.h
SRC = check.c \
	init.c \
	monitors.c \
	philo_routine_helpers.c \
	helpers_2.c \
	main.c \
	threads.c \
	helpers.c \
	philo_routine.c
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