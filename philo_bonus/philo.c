/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/22 15:46:10 by abellakr         ###   ########.fr       */
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
	free(shared_data.pid_table);
	return (0);
}

//--------------------------------------------------------
void	init_data(t_args *shared_data)
{
	sem_unlink("forks");
	sem_unlink("print");
	shared_data->forks = sem_open("forks", O_CREAT, S_IRWXU, \
	shared_data->number_philos);
	shared_data->print = sem_open("print", O_CREAT, S_IRWXU, 1);
}

//-----------------------------------------------------
void	create_process(t_args *shared_data)
{
	int	i;

	i = 1;
	shared_data->pid_table = \
	(int *)malloc(sizeof(int) * shared_data->number_philos);
	shared_data->start_time = ft_gettime();
	while (i <= shared_data->number_philos)
	{
		shared_data->pid_table[i - 1] = fork();
		if (shared_data->pid_table[i - 1] == 0)
		{
			shared_data->philo_id = i;
			pthread_create(&(shared_data->check_dead), NULL, \
			(void *)dead, shared_data);
			handle_cases(shared_data);
		}
		i++;
	}
	wait_function(shared_data);
}

//------------------------------
void	wait_function(t_args *shared_data)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	j = 0;
	while (j < shared_data->number_philos)
	{
		if (waitpid(0, &tmp, 0) > 0)
		{
			if (tmp != 0)
			{
				while (++i < shared_data->number_philos)
					kill (shared_data->pid_table[i], SIGINT);
			}
		}
		j++;
	}
}

// ---------------------
// ./philo 5 800 200 200 no one should die
// ./philo 5 800 200 200 7  no one should die and sim stop in 7 
// ./philo 4 410 200 200 no one should die
// ./philo 4 310 200 100  one should die