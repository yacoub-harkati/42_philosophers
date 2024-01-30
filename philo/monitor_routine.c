/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:24:49 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/30 01:05:43 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	dead_loop(t_data *data)
{
	if (check_any_philo_died(data) || check_all_philo_eat(data, false))
		return (false);
	return (true);
}

void	*monitor_routine(void *data)
{
	t_data	*dt;

	dt = (t_data *)data;
	while (true)
	{
		if (check_any_philo_died(dt) || check_all_philo_eat(dt, true))
			return (NULL);
	}
	return (dt);
}
