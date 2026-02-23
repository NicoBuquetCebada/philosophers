/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 15:31:48 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/23 19:22:21 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_dead(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->meal_lock);
	if (get_time() - philo->last_meal >= data->time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(&data->meal_lock), 1);
	pthread_mutex_unlock(&data->meal_lock);
	return (0);
}

static int	check_alive(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (is_dead(data, &data->philos[i]))
		{
			print_routine("died", &data->philos[i]);
			pthread_mutex_lock(&data->dead_lock);
			data->dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_meals(t_data *data)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (data->number_of_times_each_philosopher_must_eat == -1)
		return (0);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->meal_lock);
		if (data->philos[i].meal_c
			>= data->number_of_times_each_philosopher_must_eat)
			finished_eating++;
		pthread_mutex_unlock(&data->meal_lock);
		i++;
	}
	if (finished_eating == data->number_of_philosophers)
	{
		pthread_mutex_lock(&data->dead_lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	while (1)
		if (!check_alive(data) || check_meals(data))
			break ;
	return (pointer);
}
