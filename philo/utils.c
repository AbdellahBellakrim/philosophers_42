/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:50:19 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/13 17:11:16 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------------------------------------------
int	parsing(int ac, char **av, t_args *shared_data)
{
	if(check_arguments(ac, av) == 0)
	{
		//free memory allocated
		write(2, "invalid arguments\n", 18);
		return(-1);
	}
	shared_data->number_philos = ft_atoi(av[1]);
	shared_data->die_time = ft_atoi(av[2]);
	shared_data->eat_time = ft_atoi(av[3]);
	shared_data->sleep_time = ft_atoi(av[4]);
	if(ac == 6)
		shared_data->meal_number = ft_atoi(av[5]);
	if(shared_data->number_philos == -1 || \
	shared_data->die_time == -1 || shared_data->eat_time == -1 || \
	shared_data->sleep_time == -1 || shared_data->meal_number == -1)
		return(-1);
	return(0);
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
