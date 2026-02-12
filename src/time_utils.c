/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:10:49 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/12 01:13:38 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Returns the current system time in milliseconds.
size_t	get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		ft_error("gettimeofday: error");
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}