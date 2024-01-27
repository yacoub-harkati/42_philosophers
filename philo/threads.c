/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:40:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/27 14:19:31 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_threads(t_data *data)
{
	int			i;
	pthread_t	th[MAX_PHILO + 1];

	i = -1;
	// if (pthread_create(&th[MAX_PHILO], NULL, monitor_routine, data->philo))
	// {
	// 	printf(RED "Error: " RESET "Failed to create thread\n");
	// 	exit(EXIT_FAILURE);
	// }
	while (++i < data->num_of_philo)
	{
		if (pthread_create(&th[i], NULL, philo_routine, &data->philo[i]))
		{
			printf(RED "Error: " RESET "Failed to create thread\n");
			exit(EXIT_FAILURE);
		}
	}
	i = -1;
	while (++i < data->num_of_philo)
	{
		if (pthread_join(th[i], NULL))
		{
			printf(RED "Error: " RESET "Failed to join thread\n");
			exit(EXIT_FAILURE);
		}
	}
	// if (pthread_join(th[MAX_PHILO], NULL))
	// {
	// 	printf(RED "Error: " RESET "Failed to join thread\n");
	// 	exit(EXIT_FAILURE);
	// }
}
