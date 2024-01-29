/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:24:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/29 07:00:57 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	dead_loop(t_data *data)
{
	pthread_mutex_lock(&data->sync_mutex);
	if (check_any_philo_died(data) || check_all_philo_eat(data, true))
		exit(EXIT_SUCCESS);
	pthread_mutex_unlock(&data->sync_mutex);
	return (true);
}

void	*monitor_routine(void *data)
{
	t_data	*dt;

	dt = (t_data *)data;
	while (1)
		dead_loop(dt);
	return (NULL);
}
