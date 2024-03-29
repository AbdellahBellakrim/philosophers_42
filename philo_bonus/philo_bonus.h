/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:04:10 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/22 15:45:55 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
//----------------------------------------
# include <libc.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
// ------------------------
typedef struct t_args
{
	int				number_philos;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				meal_number;
	int				philo_id;
	sem_t			*forks;
	sem_t			*print;
	int				*pid_table;
	long			start_time;
	long			last_meal;
	pthread_t		check_dead;
	int				check_dead_var;
}t_args;
//------------------------------------------- parsing
int		check_arguments(int ac, char **av);
int		ft_isdigit(int str);
size_t	ft_strlen(const char *str);
int		ft_atoi(char *p);
char	*ft_trizo(char *s, char c);
int		check_max(long long number, int signe);
int		parsing(int ac, char **av, t_args *args);
//-------------------------------------------
void	init_data(t_args *shared_data);
void	create_process(t_args *shared_data);
void	handle_cases(t_args *shared_data);
void	routine(t_args *shared_data);
void	eating_function(t_args *shared_data);
void	sleeping_function(t_args *shared_data);
void	thinking_function(t_args *shared_data);
void	dead(void *shared_data);
//------------------------------------------------
long	ft_gettime(void);
void	sleep_function(long current_time, int time);
void	wait_function(t_args *shared_data);
#endif
