/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:55:30 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/20 18:59:30 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//----------------------------------------------------
void	handle_cases(t_args *shared_data)
{
	int i;
	
	i = -1;
	if (shared_data->meal_number == -1)
	{
		while(1)
			routine(shared_data);
	}
	else 
	{
		while(++i < shared_data->meal_number)
			routine(shared_data);
		exit(0);
	}
}
//-------------------------------------------- routine 
void	routine(t_args *shared_data)
{
	if (shared_data->philo_id % 2 == 0)
		usleep(500);
	eating_function(shared_data);
	sleeping_function(shared_data);
	thinking_function(shared_data);
}
//-----------------------------------------------
void	eating_function(t_args *shared_data)
{
	long	time;

	time = ft_gettime();
	sem_wait(shared_data->forks);
	sem_wait(shared_data->forks);
	printf("%d has taken a fork\n", shared_data->philo_id);
	printf("%d is eating\n", shared_data->philo_id);
	sleep_function(time, shared_data->eat_time);
	sem_post(shared_data->forks);
	sem_post(shared_data->forks);
}
//-------------------------------------------------
void sleeping_function(t_args *shared_data)
{
	long 	time;

	time = ft_gettime();
	printf("%d is sleeping\n", shared_data->philo_id);
	sleep_function(time, shared_data->sleep_time);
}
//--------------------------------------------------------
void	thinking_function(t_args *shared_data)
{
	printf("%d is thinking\n", shared_data->philo_id);
}
