/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:50:19 by abellakr          #+#    #+#             */
/*   Updated: 2022/04/16 16:21:40 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------------------------------------------
void parsing(int ac, char **av, t_args *args)
{
	if(check_arguments(ac, av) == 0)
	{
		//free memory allocated
		write(2, "invalid arguments\n", 18);
		exit(1);
	}
	args->number_philos = av[1];
	args->die_time = av[2];
	args->eat_time = av[3];
	args->sleep_time = av[4];
	if(ac == 6)
		args->meal_number = av[5];
}
//-------------------------------------------------
int	ft_isdigit(int str)
{
	if (str >= 48 && str <= 57)
		return (1);
	else
		return (0);
}
//-------------------------------------------------
int	check_arguments(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 5)
	{
		while(i <= 5)
		{
			if(ft_isdigit(av[i]) == 0)
				return (0);
			i++;
		}
	}
	else if(ac == 6)
	{
		while(i <= 6)
		{
			if(ft_isdigit(av[i]) == 0)
				return (0);
			i++;
		}
	}
	return (1);
}