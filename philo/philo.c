/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:24 by abellakr          #+#    #+#             */
/*   Updated: 2022/04/16 16:20:17 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_args *args;

	if(ac != 5 || ac != 6)
		return(write(2, "invalid arguments\n", 18), 1);
	args = (t_args *)malloc(sizeof(t_args));
	if(!args)
		return(write(2, "out of memory\n", 14), 1);
	parsing(ac, av, args);
}