/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:06:34 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/02 04:23:55 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	check_args(ac, av);
	init_data(ac, av, &data);
	init_mutex(&data);
	init_philo(&data);
	start_threads(&data);
	// pthread_exit(NULL);
	return (EXIT_SUCCESS);
}
