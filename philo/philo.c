/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:19:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/29 05:07:49 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	print_message(ph, FORK);
	if (ph->data->num_of_philo == 1)
	{
		ft_usleep(ph->data->time_to_die);
		ph->is_dead = true;
		print_message(ph, DIED);
		pthread_mutex_unlock(ph->sync_mutex);
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
	if (!ph->is_dead)
	{
		print_message(ph, SLEEP);
		ft_usleep(ph->data->time_to_sleep);
	}
}

void	philo_think(t_philo *ph)
{
	if (!ph->is_dead)
		print_message(ph, THINK);
}

void	philo_eat(t_philo *ph)
{
	philo_take_forks(ph);
	pthread_mutex_lock(ph->sync_mutex);
	if (get_current_time() - ph->last_eat > ph->data->time_to_die
		&& !check_any_philo_died(ph->data))
	{
		ph->is_dead = true;
		print_message(ph, DIED);
		pthread_mutex_unlock(ph->sync_mutex);
		return ;
	}
	if (!ph->is_dead)
		print_message(ph, EAT);
	ph->last_eat = get_current_time();
	ph->eat_count++;
	pthread_mutex_unlock(ph->sync_mutex);
	ft_usleep(ph->data->time_to_eat);
	philo_release_forks(ph);
}

void	*philo_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		philo_think(ph);
		philo_eat(ph);
		philo_sleep(ph);
	}
	return (NULL);
}
