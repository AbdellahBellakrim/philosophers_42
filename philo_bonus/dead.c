/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:53:11 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/22 15:43:30 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//-----------------------------------------------------------------------
void	dead(void *shared_data)
{
	t_args	*tmp;

	tmp = (t_args *)shared_data;
	while (1)
	{
		if (tmp->check_dead_var == 1)
		{
			if (ft_gettime() - tmp->last_meal > tmp->die_time)
			{	
				sem_wait(tmp->print);
				printf("%ld %d died\n", ft_gettime() - tmp->start_time, \
				tmp->philo_id);
				exit(1);
			}		
		}
	}
}
