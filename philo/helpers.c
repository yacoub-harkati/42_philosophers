/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:29:37 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/27 13:59:08 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	size_t				i;
	unsigned long long	number;
	int					sign;

	i = 0;
	sign = 1;
	number = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
		number = number * 10 + nptr[i++] - 48;
	return (number * sign);
}

int	get_current_time(void)
{
	struct timeval	time;
	int				current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

void	ft_usleep(int time)
{
	int	start;

	start = get_current_time();
	while (get_current_time() - start < time)
		usleep(100);
}

bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	print_message(t_philo *philo, int message_type)
{
	int	current_time;

	pthread_mutex_lock(philo->print);
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
		printf("All philosophers have eaten enough\n");
	pthread_mutex_unlock(philo->print);
}

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