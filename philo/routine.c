/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:13:11 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/15 14:02:07 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	philo->meals_eaten++;
	if(philo->meals_eaten == philo->shared_data->meal_number)
		philo->shared_data->satisfied++;
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