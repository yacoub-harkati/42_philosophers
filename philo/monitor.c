/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:24:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/28 01:00:22 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_routine(void *data)
{
	t_data	*dt;

	dt = (t_data *)data;
	while (1)
	{
		if (!check_philo_eat_status(dt) || !check_philo_died(dt))
			exit(EXIT_SUCCESS);
	}
	return (NULL);
}
