/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:40:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/30 01:03:24 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(pthread_t *th, t_data *data)
{
	int		i;
	void	*status;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (pthread_detach(th[i]))
		{
			printf(RED "Error: " RESET "Failed to detach thread\n");
			exit(EXIT_FAILURE);
		}
	}
	if (pthread_join(th[MAX_PHILO], &status))
	{
		printf(RED "Error: " RESET "Failed to join monitor thread\n");
		exit(EXIT_FAILURE);
	}
	if (status == NULL)
		destroy_mutex(data);
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
