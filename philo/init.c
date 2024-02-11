/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:59:05 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 15:42:57 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->sync_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
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
		data->philo[i].data = data;
		data->philo[i].last_eat = init_timestamp;
		data->philo[i].left_fork = data->forks + ft_min(left_i, right_i);
		data->philo[i].right_fork = data->forks + ft_max(left_i, right_i);
		i++;
	}
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->sync_mutex);
	pthread_mutex_destroy(&data->print_mutex);
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
			data->time_to_die = ft_atoi(av[i]) + 1;
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
	data->is_dead = false;
	check_input_error(data);
	data->start_time = get_current_time();
}
