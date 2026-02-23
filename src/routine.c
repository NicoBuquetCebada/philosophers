/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:05:05 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/22 16:02:30 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_routine(char *msg, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->write_lock);
	time = get_time() - philo->start_time;
	if (!check_dead(philo))
		printf("%zu %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_routine("has taken a fork", philo);
	if (philo->data->number_of_philosophers == 1)
	{
		ft_usleep(philo->data->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_routine("has taken a fork", philo);
	philo->eating = 1;
	print_routine("is eating", philo);
	pthread_mutex_lock(&philo->data->meal_lock);
	philo->last_meal = get_time();
	philo->meal_c++;
	pthread_mutex_unlock(&philo->data->meal_lock);
	ft_usleep(philo->data->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	dream(t_philo *philo)
{
	print_routine("is sleeping", philo);
	ft_usleep(philo->data->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_routine("is thinking", philo);
}
