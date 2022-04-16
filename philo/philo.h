/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:33 by abellakr          #+#    #+#             */
/*   Updated: 2022/04/16 17:24:20 by abellakr         ###   ########.fr       */
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
size_t	ft_strlen(const char *str);
void	parsing(int ac, char **av, t_args *args);
int		ft_atoi(char *p);
char	*ft_trizo(char *s, char c);
int		check_max(long long number, int signe);
#endif