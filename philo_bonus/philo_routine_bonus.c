/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:19:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/19 17:26:15 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

bool	shoul_enter_loop(t_philo *ph)
{
	sem_wait(ph->data->sem_sync);
	if (ph->data->is_over)
	{
		sem_post(ph->data->sem_sync);
		return (false);
	}
	sem_post(ph->data->sem_sync);
	return (true);
}

void	philo_routine(void *philo)
{
	t_philo		*ph;
	pthread_t	monitor;

	ph = (t_philo *)philo;
	pthread_create(&monitor, NULL, check_philo, philo);
	pthread_detach(monitor);
	while (shoul_enter_loop(ph))
	{
		philo_eat(ph);
		philo_think(ph);
		philo_sleep(ph);
	}
	if (ph->data->num_of_philo == 1)
	{
		printf(YELLOW "%d" RESET " %d " RED "died\n" RESET, get_current_time()
			- ph->data->start_time, ph->id);
		destroy_semaphore(ph->data);
		exit(EXIT_SUCCESS);
	}
	destroy_semaphore(ph->data);
	exit(EXIT_SUCCESS);
}
