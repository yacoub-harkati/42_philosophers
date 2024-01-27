/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaharkat <yaharkat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:34:10 by yaharkat          #+#    #+#             */
/*   Updated: 2024/01/27 13:15:33 by yaharkat         ###   ########.fr       */
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
			printf(RED "Error:" RESET " Argument %d ('%s') is not a valid number.\n", i, str);
			exit(EXIT_FAILURE);
		}
	}
}
