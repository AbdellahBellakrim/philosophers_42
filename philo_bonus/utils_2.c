/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:53:40 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/20 15:16:34 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
//------------------------------------------------ time function
long	ft_gettime(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

//------------------------------ sleep  function
void	sleep_function(long current_time, int time)
{
	int	a;

	a = time * 1000;
	while (ft_gettime() - current_time < a / 1000)
		usleep(100);
}
