/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:39:03 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/22 16:58:10 by nbuquet-         ###   ########.fr       */
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
		ft_usleep(1);
	while (!check_dead(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

int	thread_create(t_data *data, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	observer;

	if (pthread_create(&observer, NULL, &monitor, data) != 0)
		clean_data(data, forks, "thread: creation error");
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]) != 0)
			clean_data(data, forks, "thread: creation error");
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		clean_data(data, forks, "thread: join error");
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			clean_data(data, forks, "thread: join error");
		i++;
	}
	return (0);
}
