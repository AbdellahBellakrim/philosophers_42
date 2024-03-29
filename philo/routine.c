/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:13:11 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/18 18:42:47 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//-------------------------------------------- routine 
void	routine(void *philo)
{
	t_philo	*backup;

	backup = (t_philo *)philo;
	backup->start_time = ft_gettime();
	if (backup->id % 2 == 0)
		usleep(500);
	while (backup->shared_data->dead == 0 && backup->shared_data->satisfied != \
	backup->shared_data->number_philos)
	{
		eating_function(backup);
		sleeping_function(backup);
		thinking_function(backup);
	}
}

//-------------------------------------------- eating function
int	eating_function(t_philo *philo)
{
	t_philo	*left_fork;

	if (philo->next == NULL)
		left_fork = philo->shared_data->head;
	else
		left_fork = philo->next;
	eating_cases(philo, left_fork);
	return (0);
}

//------------------------------------------------ sleeping function
int	sleeping_function(t_philo *philo)
{
	long	time;

	time = (ft_gettime() - philo->start_time);
	if (philo->shared_data->dead == 0)
	{
		pthread_mutex_lock(&(philo->shared_data->print));
		printf("%ld %d is sleeping\n", time, philo->id);
		pthread_mutex_unlock(&(philo->shared_data->print));
		sleep_function(ft_gettime(), philo->shared_data->sleep_time);
	}
	return (0);
}

//--------------------------------------------- thinking_function
int	thinking_function(t_philo *philo)
{
	long	time;

	time = (ft_gettime() - philo->start_time);
	if (philo->shared_data->dead == 0)
	{
		pthread_mutex_lock(&(philo->shared_data->print));
		printf("%ld %d is thinking\n", time, philo->id);
		pthread_mutex_unlock(&(philo->shared_data->print));
	}
	return (0);
}

//----------------------------------------------- 
void	eating_cases(t_philo *philo, t_philo *left_fork)
{
	long	time;

	if (philo->shared_data->dead == 0)
	{
		pthread_mutex_lock (&(philo->fork));
		pthread_mutex_lock (&(left_fork->fork));
		time = (ft_gettime() - philo->start_time);
		pthread_mutex_lock(&(philo->shared_data->print));
		printf ("%ld %d has taken a fork\n", time, philo->id);
		pthread_mutex_unlock(&(philo->shared_data->print));
		pthread_mutex_lock(&(philo->shared_data->print));
		printf ("%ld %d  is eating\n", time, philo->id);
		pthread_mutex_unlock(&(philo->shared_data->print));
		sleep_function (ft_gettime(), philo->shared_data->eat_time);
		philo->last_meal = ft_gettime();
		philo->meals_eaten++;
		if (philo->meals_eaten == philo->shared_data->meal_number)
			philo->shared_data->satisfied++;
		pthread_mutex_unlock (&(philo->fork));
		pthread_mutex_unlock (&(left_fork->fork));
	}
}
