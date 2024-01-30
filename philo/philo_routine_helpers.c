/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:57:01 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/30 03:52:19 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	print_message(ph, FORK);
	if (ph->data->num_of_philo == 1)
	{
		ph->last_eat = get_current_time();
		ft_usleep(ph->data->time_to_die);
		return ;
	}
	pthread_mutex_lock(ph->right_fork);
	print_message(ph, FORK);
}

void	philo_release_forks(t_philo *ph)
{
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
}

void	philo_sleep(t_philo *ph)
{
	print_message(ph, SLEEP);
	ft_usleep(ph->data->time_to_sleep);
}

void	philo_think(t_philo *ph)
{
	print_message(ph, THINK);
}

void	philo_eat(t_philo *ph)
{
	philo_take_forks(ph);
	pthread_mutex_lock(ph->sync_mutex);
	ph->last_eat = get_current_time();
	if (ph->is_dead)
	{
		pthread_mutex_unlock(ph->sync_mutex);
		return ;
	}
	ph->eat_count++;
	pthread_mutex_unlock(ph->sync_mutex);
	print_message(ph, EAT);
	ft_usleep(ph->data->time_to_eat);
	philo_release_forks(ph);
}
