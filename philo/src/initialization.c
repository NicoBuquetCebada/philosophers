/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:15:17 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/12 01:09:28 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data, t_philo *philos, char **av)
{
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->number_of_times_each_philosopher_must_eat = -1;
	if (av[5])
		data->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	data->philos = philos;
	data->dead = 0;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
}

void	init_forks(pthread_mutex_t *forks, int number_of_philosophers)
{
	int	i;

	i = 0;
	while (i < number_of_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philos(t_data *data, t_philo *philos, pthread_mutex_t *forks)
{
	int		i;
	size_t	current;

	i = 0;
	current = get_time();
	while (i < data->number_of_philosophers)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meal_c = 0;
		philos[i].last_meal = current;
		philos[i].start_time = current;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[data->number_of_philosophers - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		philos[i].data = data;
		i++;
	}
}
