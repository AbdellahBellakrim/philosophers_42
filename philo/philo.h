/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:33:33 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/18 12:21:34 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H
//----------------------------------------
#include <libc.h>
#include <pthread.h>
#include <sys/time.h>
// ------------------------
typedef struct t_args 
{
	int		number_philos;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		meal_number; 
	int 	satisfied;
	int 	dead; // check if a philo is dead or not
	int 	dead_id; // died philo id
	long	dead_time;// died time of philo 
	pthread_mutex_t	print;
	struct t_philo *head;
}t_args;
//-----------------------------------------
typedef struct t_philo
{
	t_args			*shared_data;
	pthread_t 		thread;
	pthread_mutex_t	fork;
	int 			id;
	int 			meals_eaten; // check how much the philo has been eaten
	long			start_time; 
	long			last_meal; // time of the last meal 
	struct t_philo	*next;
}t_philo;
//------------------------------------------- parsing
int		check_arguments(int ac, char **av);
int		ft_isdigit(int str);
size_t	ft_strlen(const char *str);
int		ft_atoi(char *p);
char	*ft_trizo(char *s, char c);
int		check_max(long long number, int signe);
int		parsing(int ac, char **av, t_args *args);
// --------------------------  utils_2
t_philo	*ft_lstnew(int id, t_args *shared_data);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo	*ft_lstlast(t_philo **lst);
// ----------------------------------------- create data
int create_list(t_philo **philo, t_args *shared_data);
int create_threads(t_philo **philo);
// ----------------------------------------- routine
void routine(void *philo);
int eating_function(t_philo *philo);
int sleeping_function(t_philo *philo);
int thinking_function(t_philo *philo);
long	ft_gettime(void);
void	sleep_function(long current_time, int time);
#endif
