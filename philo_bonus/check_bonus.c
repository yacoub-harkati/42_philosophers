/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:34:10 by yaharkat          #+#    #+#             */
/*   Updated: 2024/02/11 21:46:54 by yaharkat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		print_error_exit("Wrong number of arguments (Expected 5 or 6).\n");
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
			printf(RED "Error: " RESET);
			printf("Argument %d ('%s') is not valid (Expected u32).\n", i, str);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_input_error(t_data *data)
{
	int		i;
	char	*s;

	s = "number_of_philosophers should be between 1 and 200 (inclusive).\n";
	i = 0;
	while (++i < 5)
	{
		if (i == 1 && (data->num_of_philo == 0 || data->num_of_philo > 200))
			print_error_exit(s);
		else if (i == 2 && data->time_to_die < 60)
			print_error_exit("time_to_die should be larger than 60ms.\n");
		else if (i == 3 && data->time_to_eat < 60)
			print_error_exit("time_to_eat should be larger than 60ms.\n");
		else if (i == 4 && data->time_to_sleep < 60)
			print_error_exit("time_to_sleep should be larger than 60ms.\n");
	}
}
