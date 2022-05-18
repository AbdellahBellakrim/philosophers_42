/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/18 12:42:13 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//------------------------------------------ 
int main(int ac, char **av)
{
	t_args shared_data;
	t_philo *philo;
	t_philo *tmp;

	philo = NULL;
	if(ac != 5 && ac != 6)
		return(write(2, "invalid arguments\n", 18), 1);
	if(parsing(ac, av, &shared_data) == -1)
		return(1);
	create_list(&philo, &shared_data);
	create_threads(&philo);
	tmp = philo;
	pthread_mutex_init(&(shared_data.print), NULL);
	while (1)
	{
		if(shared_data.satisfied == shared_data.number_philos)
			break;
		if(ft_gettime() - tmp->last_meal > tmp->shared_data->die_time)
		{
			tmp->shared_data->dead = 1;
			tmp->shared_data->dead_id = tmp->id;
			tmp->shared_data->dead_time = ft_gettime() - tmp->start_time;
			pthread_mutex_lock(&(shared_data.print));
			printf("%ld %d died\n",shared_data.dead_time ,shared_data.dead_id);
			break ;
		}
		if(tmp->next == NULL)
			tmp = tmp->shared_data->head;
		else
			tmp = tmp->next;
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
		backup->last_meal = ft_gettime();
		backup = backup->next;
	}
	return(0);
}

// check if a ph is dead
// errors of parse and malloc, all functions protection 
// check leaks 
// norme 
// bonus
// ---------------------
// ./philo 5 800 200 200 no one should die
// ./philo 5 800 200 200 7  no one should die and sim stop in 7 
// ./philo 4 410 200 200 no one should die
// ./philo 4 310 200 100  one should die