/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:40:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/29 01:41:10 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(pthread_t *th, t_data *data)
{
	int	i;

	i = -1;
	if (pthread_detach(th[MAX_PHILO]))
	{
		printf(RED "Error: " RESET "Failed to detach monitor thread\n");
		exit(EXIT_FAILURE);
	}
	while (++i < data->num_of_philo)
	{
		if (pthread_join(th[i], NULL))
		{
			printf(RED "Error: " RESET "Failed to join thread\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	create_threads(pthread_t *th, t_data *data)
{
	int	i;

	i = -1;
	if (pthread_create(&th[MAX_PHILO], NULL, monitor_routine, data))
	{
		printf(RED "Error: " RESET "Failed to create thread\n");
		exit(EXIT_FAILURE);
	}
	while (++i < data->num_of_philo)
	{
		if (pthread_create(&th[i], NULL, philo_routine, &data->philo[i]))
		{
			printf(RED "Error: " RESET "Failed to create thread\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	start_threads(t_data *data)
{
	pthread_t	th[MAX_PHILO + 1];

	create_threads(th, data);
	join_threads(th, data);
}
