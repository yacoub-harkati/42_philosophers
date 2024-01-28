/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:29:05 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/28 01:13:02 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parse_args(int ac, char **av, t_data *data)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (i == 1)
			data->num_of_philo = ft_atoi(av[i]);
		else if (i == 2)
			data->time_to_die = ft_atoi(av[i]);
		else if (i == 3)
			data->time_to_eat = ft_atoi(av[i]);
		else if (i == 4)
			data->time_to_sleep = ft_atoi(av[i]);
		else if (i == 5)
		{
			if (ac == 6)
				data->num_of_eat = ft_atoi(av[i]);
			else
				data->num_of_eat = 0;
		}
	}
}
