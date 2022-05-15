/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:13:11 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/15 15:06:52 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------------------------------------- routine 
void routine(void *philo)
{
	t_philo *backup;
	long	start_time;

	backup = (t_philo *)philo;
	start_time = ft_gettime();
	if(backup->id % 2 == 0)
		usleep(500);
	while(backup->shared_data->dead == 0)
	{
		eating_function(backup, start_time);
		sleeping_function(backup, start_time);
		thinking_function(backup, start_time);
	}
}
//-------------------------------------------- eating function
int eating_function(t_philo *philo, long start_time)
{
	t_philo	*left_fork;
	long	current_time;
	long	time;

	if(philo->next == NULL)
		left_fork = philo->shared_data->head;
	else
		left_fork = philo->next;
	pthread_mutex_lock (&(philo->fork));
	current_time = ft_gettime();
	time = (current_time - start_time) / 1000;
	printf("%ld %d had taken a fork\n",time ,philo->id);
	pthread_mutex_lock (&(left_fork->fork));
	current_time = ft_gettime();
	time = (current_time - start_time) / 1000;
	printf("%ld %d  is eating\n",time ,philo->id);
	philo->meals_eaten++;
	if(philo->meals_eaten == philo->shared_data->meal_number)
		philo->shared_data->satisfied++;
	usleep(philo->shared_data->eat_time * 1000);
	pthread_mutex_unlock (&(philo->fork));
	pthread_mutex_unlock (&(left_fork->fork));
	return (0);
}
//------------------------------------------------ sleeping function
int sleeping_function(t_philo *philo, long start_time)
{
	long	current_time;
	long	time;

	current_time = ft_gettime();
	time = (current_time - start_time) / 1000;
	printf("%ld %d is sleeping\n",time ,philo->id);
	usleep(philo->shared_data->sleep_time * 1000);
	return (0);
}
//--------------------------------------------- thinking_function
int thinking_function(t_philo *philo, long start_time)
{
	long	current_time;
	long	time;

	current_time = ft_gettime();
	time = (current_time - start_time) / 1000;
	printf("%ld %d is thinking\n",time ,philo->id);
	return (0);
}
//------------------------------------------------ time function
long	ft_gettime(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000000) + current_time.tv_usec);
}