/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:57:01 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 19:12:32 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	print_message(ph, FORK);
	if (ph->data->num_of_philo == 1)
	{
		pthread_mutex_lock(&ph->data->sync_mutex);
		ph->is_eating = false;
		ph->data->is_over = true;
		pthread_mutex_unlock(&ph->data->sync_mutex);
		ft_usleep(ph->data->time_to_die);
		return ;
	}
	pthread_mutex_lock(ph->right_fork);
	print_message(ph, FORK);
}

void	philo_release_forks(t_philo *ph)
{
	pthread_mutex_unlock(ph->left_fork);
	if (ph->data->num_of_philo != 1)
		pthread_mutex_unlock(ph->right_fork);
}

void	philo_sleep(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->sync_mutex);
	if (ph->data->is_over)
	{
		pthread_mutex_unlock(&ph->data->sync_mutex);
		return ;
	}
	pthread_mutex_unlock(&ph->data->sync_mutex);
	print_message(ph, SLEEP);
	ft_usleep(ph->data->time_to_sleep);
}

void	philo_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->sync_mutex);
	if (ph->data->is_over)
	{
		pthread_mutex_unlock(&ph->data->sync_mutex);
		return ;
	}
	pthread_mutex_unlock(&ph->data->sync_mutex);
	print_message(ph, THINK);
}

void	philo_eat(t_philo *ph)
{
	philo_take_forks(ph);
	if (ph->data->num_of_philo == 1)
		return ;
	pthread_mutex_lock(&ph->data->sync_mutex);
	ph->is_eating = true;
	ph->last_eat = get_current_time();
	ph->eat_count++;
	if (ph->eat_count == ph->data->num_of_eat)
		ph->data->num_of_full_philo++;
	if (ph->data->is_over)
	{
		pthread_mutex_unlock(&ph->data->sync_mutex);
		philo_release_forks(ph);
		return ;
	}
	pthread_mutex_unlock(&ph->data->sync_mutex);
	print_message(ph, EAT);
	ft_usleep(ph->data->time_to_eat);
	pthread_mutex_lock(&ph->data->sync_mutex);
	ph->is_eating = false;
	pthread_mutex_unlock(&ph->data->sync_mutex);
	philo_release_forks(ph);
}
