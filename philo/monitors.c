/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:24:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 19:05:10 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *data)
{
	t_data	*data_ptr;

	data_ptr = (t_data *)data;
	while (check_philo(data_ptr))
		continue ;
	return (NULL);
}

bool	check_philo(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->sync_mutex);
	while (++i < data->num_of_philo)
	{
		if (data->num_of_full_philo == data->num_of_philo)
		{
			data->is_over = true;
			pthread_mutex_unlock(&data->sync_mutex);
			print_message(&data->philo[0], OVER);
			return (false);
		}
		if (get_current_time() - data->philo[i].last_eat > data->time_to_die
			&& data->philo[i].is_eating == false)
		{
			data->is_over = true;
			pthread_mutex_unlock(&data->sync_mutex);
			print_message(&data->philo[i], DIED);
			return (false);
		}
	}
	pthread_mutex_unlock(&data->sync_mutex);
	return (true);
}
