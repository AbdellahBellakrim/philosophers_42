/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:25:27 by abellakr          #+#    #+#             */
/*   Updated: 2022/05/20 15:15:05 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

//---------------------------------------
int	check_max(long long number, int signe)
{
	number = number * signe;
	if (number > INT_MAX || number < INT_MIN)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (number);
}

//---------------------------------------
char	*ft_trizo(char *s, char c)
{
	unsigned long	i;
	unsigned long	j;
	char			*tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
			break ;
		i++;
	}
	tab = malloc(sizeof(char *) * (ft_strlen(s) - i + 1));
	if (!tab)
		return (NULL);
	while (i < ft_strlen(s))
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

//---------------------------------------
int	ft_atoi(char *p)
{
	long long		k;
	int				signe;

	signe = 1;
	k = 0;
	if (*p == '+')
		p++;
	if (*p == '-')
	{
		signe = -signe;
		p++;
	}
	p = ft_trizo(p, '0');
	if (ft_strlen(p) > 11)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	free(p);
	while (*p >= '0' && *p <= '9')
	{
		k = k * 10 + (*p - 48);
		p++;
	}
	return (check_max(k, signe));
}
