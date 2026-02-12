/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:39:03 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/12 01:30:33 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_lock);
	if (philo->data->dead == 1)
		return (pthread_mutex_unlock(&philo->data->dead_lock), 1);
	pthread_mutex_unlock(&philo->data->dead_lock);
	return (0);
}

void	*routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		usleep(1); // ¿no funciona bien?
	while (!check_dead(philo)) // bucle infinito hasta monitorizar
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

int	thread_create(t_data *data) // falta monitorizar
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]) != 0)
			ft_error("thread: creation error"); // clean
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			ft_error("thread: join error"); // clean
		i++;
	}
	return (0);
}
