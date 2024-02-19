/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:24:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/19 17:40:12 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_philo(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		sem_wait(ph->data->sem_sync);
		if (ph->eat_count == ph->data->num_of_eat && ph->data->num_of_eat > 0)
		{
			ph->data->is_over = true;
			sem_post(ph->data->sem_sync);
			return (NULL);
		}
		if (get_current_time() - ph->last_eat > ph->data->time_to_die
			&& ph->is_eating == false)
		{
			ph->data->is_over = true;
			sem_post(ph->data->sem_sync);
			sem_wait(ph->data->sem_died);
			print_message(ph, DIED);
			return (NULL);
		}
		sem_post(ph->data->sem_sync);
	}
	return (NULL);
}
