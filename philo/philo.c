/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/12 17:00:36 by abellakr         ###   ########.fr       */
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
	if(parsing(ac, av, &shared_data) == -1)
		return(1);
	create_list(&philo, &shared_data);
	// while(philo != NULL)
	// {
	// 	printf("%d\n", philo->id);
	// 	philo = philo->next;
	// }
	return(0);
}
//------------------------------------------------ create threads
int create_threads(t_philo **philo, t_args *shared_data)
{
	t_philo *backup;

	backup = *philo;
	while(backup)
	{
		pthread_create(backup->thread, NULL, routine, &backup);
		backup = backup->next;
	}
	return(0);
}
//--------------------------------------------
void routine(void *philo)
{
	t_philo *backup;

	backup = (t_philo *)philo;
	if(backup->id % 2 == 0)
		usleep(500);
	while(backup->shared_data->dead == 0)
	{
		// eating_function
		// sleeping_function
		// thinking_function
	}
}
//--------------------------------------------
int eating_function(t_philo *philo)
{
	t_philo *left_fork;

	left_fork = philo->next;
}