/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:19:11 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/27 14:04:36 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_take_forks(t_philo *ph)
{
	pthread_mutex_lock(ph->left_fork);
	pthread_mutex_lock(ph->right_fork);
	print_message(ph, FORK);
	print_message(ph, FORK);
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
	pthread_mutex_lock(ph->eat_mutex);
	if (!ph->data->died_flag)
	{
		ph->last_eat = get_current_time();
		ph->eat_count++;
		print_message(ph, EAT);
		ft_usleep(ph->data->time_to_eat);
	}
	pthread_mutex_unlock(ph->eat_mutex);

}
void	*philo_routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		philo_take_forks(ph);
		philo_eat(ph);
		philo_sleep(ph);
		philo_think(ph);
	}
	return (NULL);
}
