/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:59:05 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/27 14:04:56 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_mutex(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
}

void	init_philo(t_data *data)
{
	int i;
	int left_i;
	int right_i;

	i = 0;
	while (i < data->num_of_philo)
	{
		left_i = i;
		right_i = (i + 1) % data->num_of_philo;
		data->philo[i].id = i + 1;
		data->philo[i].eat_count = 0;
		data->philo[i].data = data;
		data->philo[i].left_fork = data->forks + ft_min(left_i, right_i);
		data->philo[i].right_fork = data->forks + ft_max(left_i, right_i);
		data->philo[i].eat_mutex = &data->eat_mutex;
		data->philo[i].dead_mutex = &data->dead_mutex;
		data->philo[i].print = &data->print;
		i++;
	}
}

void destroy_mutex(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
}
