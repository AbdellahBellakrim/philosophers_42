/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/15 16:07:49 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//------------------------------------------ 
int main(int ac, char **av)
{
	t_args shared_data;
	t_philo *philo;

	philo = NULL;
	if(ac != 5 && ac != 6)
		return(write(2, "invalid arguments\n", 18), 1);
	if(parsing(ac, av, &shared_data) == -1)
		return(1);
	create_list(&philo, &shared_data);
	create_threads(&philo);
	while (1)
	{
		if(shared_data.satisfied == shared_data.number_philos || shared_data.dead == 1)
			break;
	}
	return(0);
}
//--------------------------------- create lincked list 
int create_list(t_philo **philo, t_args *shared_data)
{
	int i;
	t_philo *backup;

	i = 1;
	while(i <= shared_data->number_philos)
	{
		backup = ft_lstnew(i, shared_data);
		ft_lstadd_back(philo, backup);
		if(i == 1)
			shared_data->head = *philo;
		i++;
	}
	return(0);
}
//------------------------------------------------ create threads
int create_threads(t_philo **philo)
{
	t_philo *backup;

	backup = *philo;
	while(backup)
	{
		pthread_create(&(backup->thread), NULL, (void *)routine, backup);
		backup = backup->next;
	}
	return(0);
}

// time for each ph 
// check if a ph is dead
// errors of parse and malloc, all functions protection 
// check leaks 
// norme 
// bonus



// current_time  = ft_gettime(void);

// print ((current_time - start_time) / 1000)