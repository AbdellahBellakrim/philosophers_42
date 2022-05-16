/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:13:11 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/16 20:32:41 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------------------------------------- routine 
void routine(void *philo)
{
	t_philo *backup;

	backup = (t_philo *)philo;
	backup->start_time = ft_gettime();
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
	t_philo	*left_fork;
	long	time;

	if(philo->next == NULL)
		left_fork = philo->shared_data->head;
	else
		left_fork = philo->next;
	pthread_mutex_lock (&(philo->fork));
	pthread_mutex_lock (&(left_fork->fork));
	time = (ft_gettime() - philo->start_time);
	printf("%ld %d has taken a fork\n",time ,philo->id);
	printf("%ld %d  is eating\n",time ,philo->id);
	sleep_function(ft_gettime(), philo->shared_data->eat_time); // function to sleep
	// usleep(philo->shared_data->eat_time * 1000);
	philo->last_meal = ft_gettime();
	philo->meals_eaten++;
	if(philo->meals_eaten == philo->shared_data->meal_number)
		philo->shared_data->satisfied++;
	pthread_mutex_unlock (&(philo->fork));
	pthread_mutex_unlock (&(left_fork->fork));
	return (0);
}
//------------------------------------------------ sleeping function
int sleeping_function(t_philo *philo)
{
	long	time;

	time = (ft_gettime() - philo->start_time);
	if(ft_gettime() - philo->last_meal > philo->shared_data->die_time)
	{
		philo->shared_data->dead = 1;
		philo->shared_data->dead_id = philo->id;
		philo->shared_data->dead_time = ft_gettime() - philo->start_time;
	}
	printf("%ld %d is sleeping\n",time ,philo->id);
	// usleep(philo->shared_data->sleep_time * 1000);
	sleep_function(ft_gettime(), philo->shared_data->sleep_time);  // functin to sleep 
	return (0);
}
//--------------------------------------------- thinking_function
int thinking_function(t_philo *philo)
{
	long	time;

	time = (ft_gettime() - philo->start_time);
	printf("%ld %d is thinking\n",time ,philo->id);
	return (0);
}
//------------------------------ sleep  function
void	sleep_function(long current_time, int time)
{
	int a;
	
	a = time * 1000;
	while(ft_gettime() - current_time < a / 1000)
		usleep(100);
}