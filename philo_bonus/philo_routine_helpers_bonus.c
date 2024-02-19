/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_helpers_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:57:01 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/18 18:49:31 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_take_forks(t_philo *ph)
{
	sem_wait(ph->data->sem_forks);
	print_message(ph, FORK);
	if (ph->data->num_of_philo == 1)
	{
		sem_wait(ph->data->sem_sync);
		ph->is_eating = false;
		ph->data->is_over = true;
		sem_post(ph->data->sem_sync);
		ft_usleep(ph->data->time_to_die);
		return ;
	}
	sem_wait(ph->data->sem_forks);
	print_message(ph, FORK);
}

void	philo_release_forks(t_philo *ph)
{
	sem_post(ph->data->sem_forks);
	if (ph->data->num_of_philo != 1)
		sem_post(ph->data->sem_forks);
}

void	philo_sleep(t_philo *ph)
{
	sem_wait(ph->data->sem_sync);
	if (ph->data->is_over)
	{
		sem_post(ph->data->sem_sync);
		return ;
	}
	sem_post(ph->data->sem_sync);
	print_message(ph, SLEEP);
	ft_usleep(ph->data->time_to_sleep);
}

void	philo_think(t_philo *ph)
{
	sem_wait(ph->data->sem_sync);
	if (ph->data->is_over)
	{
		sem_post(ph->data->sem_sync);
		return ;
	}
	sem_post(ph->data->sem_sync);
	print_message(ph, THINK);
}

void	philo_eat(t_philo *ph)
{
	philo_take_forks(ph);
	if (ph->data->num_of_philo == 1)
		return ;
	sem_wait(ph->data->sem_sync);
	ph->is_eating = true;
	ph->last_eat = get_current_time();
	ph->eat_count++;
	if (ph->eat_count == ph->data->num_of_eat)
		ph->data->num_of_full_philo++;
	if (ph->data->is_over)
	{
		sem_post(ph->data->sem_sync);
		philo_release_forks(ph);
		return ;
	}
	sem_post(ph->data->sem_sync);
	print_message(ph, EAT);
	ft_usleep(ph->data->time_to_eat);
	sem_wait(ph->data->sem_sync);
	ph->is_eating = false;
	sem_post(ph->data->sem_sync);
	philo_release_forks(ph);
}
