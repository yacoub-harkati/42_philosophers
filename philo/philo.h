/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:18:16 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 15:42:24 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILO 300
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
// Escape code colors
# define RESET "\033[0m"
# define RED "\033[31m"
# define YELLOW "\033[33m"

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
	int					eat_count;
	long				last_eat;
	bool				*is_dead;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*print_mutex;
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
	bool				is_dead;
	pthread_mutex_t		sync_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		forks[MAX_PHILO];
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
void					init_mutex(t_data *data);
void					destroy_mutex(t_data *data);
void					*philo_routine(void *philo);
void					*monitor_routine(void *philo);
void					start_threads(t_data *data);
bool					check_all_philo_eat(t_data *data);
bool					check_any_philo_died(t_data *data);
bool					dead_loop(t_data *data);
void					print_error_exit(char *error_message);
void					check_input_error(t_data *data);
void					philo_eat(t_philo *ph);
void					philo_think(t_philo *ph);
void					philo_sleep(t_philo *ph);
void					philo_release_forks(t_philo *ph);
void					philo_take_forks(t_philo *ph);
#endif