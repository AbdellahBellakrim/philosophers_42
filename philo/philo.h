/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:33 by abellakr          #+#    #+#             */
/*   Updated: 2022/04/20 22:20:12 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
//----------------------------------------
#include <libc.h>
#include <pthread.h>
// ------------------------
typedef struct t_args 
{
	int		number_philos;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		meal_number;
}t_args;
//-----------------------------------------
typedef struct t_philo
{
	t_args *args;
	int philo_id;
	int max_eat;
	pthread_mutex_t mut;
}t_philo;
//-------------------------------------------
int		check_arguments(int ac, char **av);
int		ft_isdigit(int str);
size_t	ft_strlen(const char *str);
void	parsing(int ac, char **av, t_args *args);
int		ft_atoi(char *p);
char	*ft_trizo(char *s, char c);
int		check_max(long long number, int signe);
void	init_philos(t_philo *data);
void*	routine();
#endif