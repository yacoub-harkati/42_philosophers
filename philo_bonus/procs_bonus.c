/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procs_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:40:59 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/19 17:25:33 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_proc(t_data *data)
{
	int		i;
	pid_t	proc_id;
	int		status;

	i = -1;
	while (++i < data->num_of_philo)
	{
		proc_id = fork();
		if (proc_id < 0)
			kill_all_proc(data);
		if (proc_id == 0)
			philo_routine(&data->philo[i]);
		else
			data->philo[i].pid = proc_id;
	}
	waitpid(-1, &status, 0);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == EXIT_SUCCESS)
			kill_all_proc(data);
	}
}

void	destroy_semaphore(t_data *data)
{
	sem_close(data->sem_forks);
	sem_close(data->sem_print);
	sem_close(data->sem_sync);
	sem_close(data->sem_died);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_SYNC);
	sem_unlink(SEM_DEATH);
}
