/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/22 13:53:53 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
//------------------------------------------ 
int	main(int ac, char **av)
{
	t_args	shared_data;

	if (ac != 5 && ac != 6)
		return (write(2, "invalid arguments\n", 18), 1);
	if (parsing(ac, av, &shared_data) == -1)
		return (1);
	init_data(&shared_data);
	create_process(&shared_data);
	return (0);
}
//--------------------------------------------------------
void	init_data(t_args *shared_data)
{
	sem_unlink("forks");
	shared_data->forks = sem_open("forks", O_CREAT, S_IRWXU, shared_data->number_philos);
}
//-----------------------------------------------------------------------------------
void	create_process(t_args *shared_data)
{
	int i;
	int	j;
	int tmp;

	i = 1;
	j = 0;
	shared_data->pid_table = (int *)malloc(sizeof(int) * shared_data->number_philos);
	shared_data->start_time = ft_gettime();
	while(i <= shared_data->number_philos)
	{
		shared_data->pid_table[i - 1] = fork();
		if(shared_data->pid_table[i - 1] == 0)
		{
			shared_data->philo_id = i;
			pthread_create(&(shared_data->check_dead), NULL, (void *)dead, shared_data);
			handle_cases(shared_data);
		}
		i++;
	}
	while (j < shared_data->number_philos)
	{
		if(waitpid(0, &tmp, 0) > 0)
		{
			if(tmp != 0)
			{
				i = -1;
				while(++i < shared_data->number_philos)
					kill(shared_data->pid_table[i], SIGINT);			
			}
		}
		j++;
	}
	
}
//-----------------------------------------------------------------------
void	dead(void *shared_data)
{
	t_args *tmp;

	tmp = (t_args *)shared_data;
	while(1)
	{
		if(tmp->check_dead_var == 1)
		{
			if (ft_gettime() - tmp->last_meal > tmp->die_time)
			{	
				printf("%ld %d died\n", ft_gettime() - tmp->start_time, \
				tmp->philo_id);
				exit(1);
			}		
		}
	}
}