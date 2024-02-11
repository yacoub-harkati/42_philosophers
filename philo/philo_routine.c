/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:19:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 16:06:18 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		philo_think(ph);
		philo_eat(ph);
		pthread_mutex_lock(&ph->data->sync_mutex);
		if (ph->data->num_of_full_philo == ph->data->num_of_philo || \
			ph->data->is_over)
		{
			pthread_mutex_unlock(&ph->data->sync_mutex);
			break ;
		}
		pthread_mutex_unlock(&ph->data->sync_mutex);
		philo_sleep(ph);
	}
	return (NULL);
}
