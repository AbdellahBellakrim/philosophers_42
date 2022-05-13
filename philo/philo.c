/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/13 19:14:24 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
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
	create_threads(&philo);
	while (1)
		sleep(1);
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
//-------------------------------------------- routine 
void routine(void *philo)
{
	t_philo *backup;

	backup = (t_philo *)philo;
	if(backup->id % 2 == 0)
		usleep(500);
	while(backup->shared_data->dead == 0)
	{
		eating_function(backup);
		sleeping_function(backup);
		thinking_function(backup);
	}
}
//-------------------------------------------- eating function
int eating_function(t_philo *philo)
{
	t_philo *left_fork;

	if(philo->next == NULL)
		left_fork = philo->shared_data->head;
	else
		left_fork = philo->next;
	pthread_mutex_lock (&(philo->fork));
	printf("%d had taken a fork\n", philo->id);
	pthread_mutex_lock (&(left_fork->fork));
	printf("%d  is eating\n", philo->id);
	usleep(philo->shared_data->eat_time * 1000);
	pthread_mutex_unlock (&(philo->fork));
	pthread_mutex_unlock (&(left_fork->fork));
	return (0);
}
//------------------------------------------------ sleeping function
int sleeping_function(t_philo *philo)
{
	printf("%d is sleeping\n", philo->id);
	usleep(philo->shared_data->sleep_time * 1000);
	return (0);
}
//--------------------------------------------- thinking_function
int thinking_function(t_philo *philo)
{
	printf("%d is thinking\n", philo->id);
	return (0);
}
// meals number for each ph
// check if a ph is dead
// time for each ph 
// errors of parse and malloc, all functions protection 
// check leaks 
// norme 
// bonus
