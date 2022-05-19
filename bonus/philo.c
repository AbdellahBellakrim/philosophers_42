/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/18 19:21:37 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//------------------------------------------ 
int	main(int ac, char **av)
{
	t_args	shared_data;

	philo = NULL;
	if (ac != 5 && ac != 6)
		return (write(2, "invalid arguments\n", 18), 1);
	if (parsing(ac, av, &shared_data) == -1)
		return (1);
	return (0);
}
// ---------------------
// ./philo 5 800 200 200 no one should die
// ./philo 5 800 200 200 7  no one should die and sim stop in 7 
// ./philo 4 410 200 200 no one should die
// ./philo 4 310 200 100  one should die