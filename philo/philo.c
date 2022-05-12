/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/12 12:19:09 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//--------------------------------- create lincked list 
int create_list(t_philo **philo, t_args *shared_data)
{
	int i;

	i = 1;
	while(i <= shared_data->number_philos)
	{
		ft_lstadd_back(philo, ft_lstnew(i, shared_data));
		i++;
	}
	return(0);
}

//------------------------------------------ 
int main(int ac, char **av)
{
	t_args shared_data;
	t_philo *philo;

	if(ac != 5 && ac != 6)
		return(write(2, "invalid arguments\n", 18), 1);
	philo = (t_philo *)malloc(sizeof(t_philo));
	if(!philo)
		return(write(2, "out of memory\n", 14), 1);
	if(parsing(ac, av, &shared_data) == -1)
		return(1);
	// printf("number of philos : %d\n", shared_data.number_philos);
	// printf("die_time : %d \n", shared_data.die_time);
	// printf("eat_time : %d \n", shared_data.eat_time);
	// printf("sleep_time : %d \n", shared_data.sleep_time);
	// printf("meal_number : %d \n", shared_data.meal_number);
	return(0);
}
