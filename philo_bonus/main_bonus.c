/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:06:34 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/19 16:28:34 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all_proc(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philo)
	{
		if (data->philo[i].pid > 0)
			kill(data->philo[i].pid, SIGINT);
	}
	destroy_semaphore(data);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	init_data(ac, av, &data);
	init_philo(&data);
	start_proc(&data);
	return (EXIT_SUCCESS);
}
