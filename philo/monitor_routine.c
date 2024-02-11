/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:24:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 16:17:21 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *data)
{
	t_data	*ph;

	ph = (t_data *)data;
	while (1)
	{
		if (check_philo_died(ph) || check_full_philo(ph))
			break ;
	}
	return (NULL);
}

bool	check_philo_died(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		pthread_mutex_lock(&data->sync_mutex);
		if (get_current_time() - data->philo[i].last_eat > data->time_to_die)
		{
			data->is_over = true;
			pthread_mutex_unlock(&data->sync_mutex);
			print_message(&data->philo[i], DIED);
			return (true);
		}
		pthread_mutex_unlock(&data->sync_mutex);
	}
	return (false);
}

bool	check_full_philo(t_data *data)
{
	pthread_mutex_lock(&data->sync_mutex);
	if (data->num_of_full_philo == data->num_of_philo)
	{
		data->is_over = true;
		pthread_mutex_unlock(&data->sync_mutex);
		print_message(NULL, OVER);
		return (true);
	}
	pthread_mutex_unlock(&data->sync_mutex);
	return (false);
}