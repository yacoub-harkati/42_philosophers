/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:34:10 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/28 01:25:31 by yaharkat         ###   ########.fr       */
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

bool	check_philo_eat_status(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->eat_mutex);
	if (!data->num_of_eat)
	{
		pthread_mutex_unlock(&data->eat_mutex);
		return (true);
	}
	while (++i < data->num_of_philo)
	{
		if (data->philo[i].eat_count != data->num_of_eat)
		{
			pthread_mutex_unlock(&data->eat_mutex);
			return (true);
		}
	}
	print_message(data->philo, OVER);
	pthread_mutex_unlock(&data->eat_mutex);
	return (false);
}

bool	check_any_philo_died(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&data->eat_mutex);
	while (++i < data->num_of_philo)
	{
		if (get_current_time() - data->start_time
			- data->philo[i].last_eat >= data->time_to_die)
		{
			print_message(data->philo + i, DIED);
			pthread_mutex_unlock(&data->eat_mutex);
			return (true);
		}
	}
	pthread_mutex_unlock(&data->eat_mutex);
	return (false);
}

bool	check_philo_died(t_data *data)
{
	pthread_mutex_lock(&data->dead_mutex);
	if (check_any_philo_died(data))
	{
		data->died_flag = true;
		pthread_mutex_unlock(&data->dead_mutex);
		return (false);
	}
	pthread_mutex_unlock(&data->dead_mutex);
	return (true);
}
