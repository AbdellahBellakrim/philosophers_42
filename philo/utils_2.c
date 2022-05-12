/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:53:40 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/12 12:18:35 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//----------------------------------  ft_lstnew
t_philo	*ft_lstnew(int id, t_args *shared_data)
{
	t_philo	*element;

	element = (t_philo *)malloc(sizeof(t_philo));
	if (!element)
		return (0);
	element->id = id;
	element->max_eat = 0;
	element->shared_data = shared_data;
	element ->next = NULL;
	return (element);
}
//------------------------------------ ft_add_back
void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*lastnode;

	if (*lst == NULL)
		(*lst) = new;
	else if (*lst != NULL)
	{
		lastnode = ft_lstlast(lst);
		lastnode->next = new;
	}
}
//---------------------------------------- find last node int list 
t_philo	*ft_lstlast(t_philo **lst)
{
	t_philo	*backup;

	backup = *lst;
	if (backup == NULL)
		return (NULL);
	while (backup->next != NULL)
		backup = backup->next;
	return (backup);
}