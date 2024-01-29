/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:34:10 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/29 04:31:43 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		printf(RED "Error:" RESET " wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	while (++i < ac)
		check_is_number(av[i], i);
}

void	check_is_number(char *str, int i)
{
	int	index;

	index = -1;
	while (str[++index])
	{
		if (!ft_isdigit(str[index]))
		{
			printf(RED "Error:" RESET);
			printf(" Argument %d ('%s') is not a valid number.\n", i, str);
			exit(EXIT_FAILURE);
		}
	}
}

bool	check_all_philo_eat(t_data *data, bool print)
{
	int	i;

	i = -1;
	// if (!print)
	// 	pthread_mutex_lock(&data->sync_mutex);
	if (!data->num_of_eat)
		return (false);
	while (++i < data->num_of_philo)
	{
		if (data->philo[i].eat_count < data->num_of_eat)
			return (false);
	}
	// if (!print)
	// 	pthread_mutex_unlock(&data->sync_mutex);
	if (print)
		print_message(data->philo, OVER);
	return (true);
}

bool	check_any_philo_died(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = data->philo;
	while (++i < data->num_of_philo)
	{
		if (philos[i].is_dead == true)
			return (true);
	}
	return (false);
}

bool	dead_loop(t_data *data)
{
	pthread_mutex_lock(&data->sync_mutex);
	if (check_any_philo_died(data) || check_all_philo_eat(data, true))
	{
		pthread_mutex_unlock(&data->sync_mutex);
		return (false);
	}
	pthread_mutex_unlock(&data->sync_mutex);
	return (true);
}
