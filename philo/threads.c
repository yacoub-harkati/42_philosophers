/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:40:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 19:11:38 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(pthread_t *th, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (pthread_join(th[i], NULL))
		{
			printf(RED "Error: " RESET "Failed to join philo thread\n");
			exit(EXIT_FAILURE);
		}
	}
	destroy_mutex(data);
}

void	create_threads(pthread_t *th, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (pthread_create(&th[i], NULL, philo_routine, &data->philo[i]))
		{
			printf(RED "Error: " RESET "Failed to create thread\n");
			exit(EXIT_FAILURE);
		}
	}
	monitor(data);
}

void	start_threads(t_data *data)
{
	pthread_t	th[MAX_PHILO + 1];

	create_threads(th, data);
	join_threads(th, data);
}
