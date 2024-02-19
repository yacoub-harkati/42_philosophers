/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:18:16 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/19 17:08:20 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <limits.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define MAX_PHILO 300
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
// Escape code colors
# define RESET "\033[0m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define SEM_FORKS "/forks"
# define SEM_PRINT "/print"
# define SEM_SYNC "/sync"
# define SEM_EAT_COUNT "/eat_count"
# define SEM_DEATH "/death"

enum					e_status
{
	EAT,
	SLEEP,
	THINK,
	FORK,
	DIED,
	OVER
};

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	pid_t				pid;
	int					eat_count;
	long				last_eat;
	bool				is_eating;
	t_data				*data;
}						t_philo;

struct					s_data
{
	int					num_of_philo;
	int					num_of_eat;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					start_time;
	int					num_of_full_philo;
	bool				is_over;
	sem_t				*sem_sync;
	sem_t				*sem_print;
	sem_t				*sem_forks;
	sem_t				*sem_eat_count;
	sem_t				*sem_died;
	t_philo				philo[MAX_PHILO];
};

void					check_args(int ac, char **av);
void					check_is_number(char *str, int i);
bool					ft_isdigit(int c);
void					ft_usleep(int time);
int						get_current_time(void);
int						ft_atoi(const char *nptr);
void					init_data(int ac, char **av, t_data *data);
int						ft_min(int a, int b);
void					init_philo(t_data *data);
void					print_message(t_philo *philo, int message_type);
int						ft_max(int a, int b);
void					init_semaphore(t_data *data);
void					destroy_semaphore(t_data *data);
void					philo_routine(void *philo);
void					start_proc(t_data *data);
void					*check_philo(void *ph);
void					print_error_exit(char *error_message);
void					check_input_error(t_data *data);
void					philo_eat(t_philo *ph);
void					philo_think(t_philo *ph);
void					kill_all_proc(t_data *data);
void					philo_sleep(t_philo *ph);
void					philo_release_forks(t_philo *ph);
void					philo_take_forks(t_philo *ph);
#endif