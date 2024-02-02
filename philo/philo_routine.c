/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:19:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/02 04:22:31 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if(ph->id % 2 == 0)
		ft_usleep(5);
	while (dead_loop(ph->data))
	{
		philo_think(ph);
		philo_eat(ph);
		philo_sleep(ph);
	}
	return (NULL);
}
