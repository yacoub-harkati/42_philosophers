/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:24:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/27 14:18:58 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *philos)
{
	t_philo *ph;
	t_philo **philosophers = (t_philo **)philos;
	int i;

	while (1)
	{
		i = 0;
		while (philosophers[i])
		{
			ph = philosophers[i];
			pthread_mutex_lock(ph->eat_mutex);
			if (get_current_time() - ph->last_eat > ph->data->time_to_die)
			{
				ph->data->died_flag = true;
				pthread_mutex_unlock(ph->eat_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(ph->eat_mutex);
			i++;
		}
	}
	return (NULL);
}
