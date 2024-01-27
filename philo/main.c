/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:06:34 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/27 14:01:54 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	data.died_flag = false;
	data.start_time = get_current_time();
	check_args(ac, av);
	parse_args(ac, av, &data);
	init_mutex(&data);
	init_philo(&data);
	start_threads(&data);
	destroy_mutex(&data);
	return (EXIT_SUCCESS);
}
