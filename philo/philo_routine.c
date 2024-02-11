/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:19:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 17:11:32 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	shoul_enter_loop(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->sync_mutex);
	if (ph->data->is_over)
	{
		pthread_mutex_unlock(&ph->data->sync_mutex);
		return (false);
	}
	pthread_mutex_unlock(&ph->data->sync_mutex);
	return (true);
}
void	*philo_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (shoul_enter_loop(ph))
	{
		philo_think(ph);
		philo_eat(ph);
		philo_sleep(ph);
	}
	return (NULL);
}
