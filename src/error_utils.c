/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:30:58 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/22 17:00:02 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_error(char *msg)
{
	size_t	len;
	
	len = ft_strlen(msg);
	write(2, "philosophers: ", 14);
	write(2, msg, len);
	write(2, "\n", 1);
	return (1);
}

void	clean_data(t_data *data, pthread_mutex_t *forks, char	*msg)
{
	int	i;

	if (msg)
		ft_error(msg);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	
}

static int	only_digits(char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
	{
		if (!ft_isdigit(a[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **av)
{
	if (ft_atoi(av[1]) <= 0 || !only_digits(av[1]) || ft_atoi(av[1]) > MAX_PHILOS)
		return (ft_error("invalid argument: number_of_philosophers"));
	if (ft_atoi(av[2]) <= 0 || !only_digits(av[2]))
		return (ft_error("invalid argument: time_to_die"));
	if (ft_atoi(av[3]) <= 0 || !only_digits(av[3]))
		return (ft_error("invalid argument: time_to_eat"));
	if (ft_atoi(av[4]) <= 0 || !only_digits(av[4]))
		return (ft_error("invalid argument: time_to_sleep"));
	if (av[5] && (ft_atoi(av[5]) < 0 || !only_digits(av[5])))
		return (ft_error("invalid argument: number_of_times_each_philosopher_must_eat"));
	return (0);
}
