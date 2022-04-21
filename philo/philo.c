/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/04/21 01:00:57 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mut; // ta nhidha 
// --------------------------------------------
void	init_philos(t_philo *data)
{

	pthread_t th[data->args->number_philos];
	int i;

	i = -1;
	data->philo_id = 1;
	while(++i < data->args->number_philos)
	{
		if(pthread_create(&th[i], NULL, &routine, data) != 0)
			exit(1);	
	}
	i = -1;
	while(++i < data->args->number_philos)
	{
		if(pthread_join(th[i], NULL) != 0)
			exit(1);
	}
}
//------------------------------------------ 
void*	routine(void *void_data)
{
	t_philo *data;
	int			i;

	data = (t_philo *)void_data; 
	pthread_mutex_lock(&mut);
	i =  data->philo_id;
	printf("me philo number %d\n", i);
	data->philo_id++;
	pthread_mutex_unlock(&mut);
	return 0;
}
//------------------------------------------ 
int main(int ac, char **av)
{
	t_philo *philo;

	if(ac != 5 && ac != 6)
		return(write(2, "invalid arguments\n", 18), 1);
	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->args = (t_args *)malloc(sizeof(t_args));
	if(!philo->args || !philo)
		return(write(2, "out of memory\n", 14), 1);
	pthread_mutex_init(&mut, NULL);
	parsing(ac, av, philo->args);
	init_philos(philo);
	return(0);
}
	// printf("number of philos : %d\n", args->number_philos);
	// printf("die_time : %d \n", args->die_time);
	// printf("eat_time : %d \n", args->eat_time);
	// printf("sleep_time : %d \n", args->sleep_time);
	// printf("meal_number : %d \n", args->meal_number);