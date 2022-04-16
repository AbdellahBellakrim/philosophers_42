/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:50:19 by abellakr          #+#    #+#             */
/*   Updated: 2022/04/16 17:46:08 by abellakr         ###   ########.fr       */
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
	args->number_philos = ft_atoi(av[1]);
	args->die_time = ft_atoi(av[2]);
	args->eat_time = ft_atoi(av[3]);
	args->sleep_time = ft_atoi(av[4]);
	if(ac == 6)
		args->meal_number = ft_atoi(av[5]);
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
	int j;

	i = 1;
	while(i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			if(ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;	
		}
		i++;
	}
	return (1);
}
//---------------------------------------------------
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}