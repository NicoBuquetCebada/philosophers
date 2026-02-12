/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:00:53 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/12 01:23:27 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: monitoring, limpieza, ¿usleep?
int	main(int ac, char **av)
{
	t_data			data;
	t_philo			philos[MAX_PHILOS];
	pthread_mutex_t	forks[MAX_PHILOS];

	if (ac < 5 || ac > 6)
		return (ft_error("Wrong number of arguments"));
	if (check_args(av))
		return (1);
	init_data(&data, philos, av);
	init_forks(forks, data.number_of_philosophers);
	init_philos(&data, philos, forks);
	thread_create(&data);
}
