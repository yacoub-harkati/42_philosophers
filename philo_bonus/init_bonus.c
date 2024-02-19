/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:59:05 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/19 17:13:56 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphore(t_data *data)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_SYNC);
	sem_unlink(SEM_DEATH);
	data->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0644, data->num_of_philo);
	data->sem_print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	data->sem_sync = sem_open(SEM_SYNC, O_CREAT, 0644, 1);
	data->sem_died = sem_open(SEM_DEATH, O_CREAT, 0644, 1);
	if (data->sem_forks == SEM_FAILED || data->sem_print == SEM_FAILED
		|| data->sem_sync == SEM_FAILED || data->sem_died == SEM_FAILED)
	{
		printf("Error: semaphore init failed\n");
		destroy_semaphore(data);
		exit(EXIT_FAILURE);
	}
}

void	init_philo(t_data *data)
{
	int	i;
	int	init_timestamp;
	int	left_i;
	int	right_i;

	i = 0;
	init_timestamp = get_current_time();
	while (i < data->num_of_philo)
	{
		left_i = i;
		right_i = (i + 1) % data->num_of_philo;
		data->philo[i].id = i + 1;
		data->philo[i].eat_count = 0;
		data->philo[i].pid = -1;
		data->philo[i].data = data;
		data->philo[i].last_eat = init_timestamp;
		i++;
	}
}

void	parse_arguments(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (i == 1)
			data->num_of_philo = ft_atoi(av[i]);
		else if (i == 2)
			data->time_to_die = ft_atoi(av[i]);
		else if (i == 3)
			data->time_to_eat = ft_atoi(av[i]);
		else if (i == 4)
			data->time_to_sleep = ft_atoi(av[i]);
		else if (i == 5)
		{
			if (ac == 6)
				data->num_of_eat = ft_atoi(av[i]);
			else
				data->num_of_eat = 0;
		}
	}
}

void	init_data(int ac, char **av, t_data *data)
{
	memset(data, 0, sizeof(t_data));
	parse_arguments(ac, av, data);
	check_input_error(data);
	data->is_over = false;
	data->num_of_full_philo = 0;
	data->start_time = get_current_time();
	init_semaphore(data);
}
