/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:29:05 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/29 21:14:55 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	print_message(t_philo *philo, int message_type)
{
	int	current_time;

	pthread_mutex_lock(philo->print_mutex);
	current_time = get_current_time() - philo->data->start_time;
	if (message_type == EAT)
		printf(YELLOW "%d" RESET " %d is eating\n", current_time, philo->id);
	else if (message_type == SLEEP)
		printf(YELLOW "%d" RESET " %d is sleeping\n", current_time, philo->id);
	else if (message_type == THINK)
		printf(YELLOW "%d" RESET " %d is thinking\n", current_time, philo->id);
	else if (message_type == FORK)
		printf(YELLOW "%d" RESET " %d has taken a fork\n", current_time,
			philo->id);
	else if (message_type == DIED)
		printf(YELLOW "%d" RESET " %d " RED "died\n" RESET, current_time,
			philo->id);
	else if (message_type == OVER)
		printf(YELLOW "%d All philosophers have eaten enough\n" RESET,
			current_time);
	pthread_mutex_unlock(philo->print_mutex);
}

void	print_error_exit(char *error_message)
{
	printf(RED "Error: " RESET);
	printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
