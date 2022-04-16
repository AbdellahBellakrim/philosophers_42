/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:33 by abellakr          #+#    #+#             */
/*   Updated: 2022/04/16 16:15:12 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
//----------------------------------------
#include <libc.h>
//-----------------------------------------
typedef struct t_args 
{
	int		number_philos;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		meal_number;
}t_args;
//-------------------------------------------
int		check_arguments(int ac, char **av);
int		ft_isdigit(int str);
void	parsing(int ac, char **av, t_args *args);
#endif