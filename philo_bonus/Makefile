CC= cc
CFLAGS= -Wall -Wextra -Werror #-fsanitize=thread -g3
NAME= philo_bonus
INCLUDES= philo_bonus.h
SRC=check_bonus.c main_bonus.c philo_routine_bonus.c \
	helpers_2_bonus.c philo_routine_helpers_bonus.c \
	helpers_bonus.c monitors_bonus.c procs_bonus.c \
	init_bonus.c
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