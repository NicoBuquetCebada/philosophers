/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbuquet- <nbuquet-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:56:06 by nbuquet-          #+#    #+#             */
/*   Updated: 2026/02/22 17:00:13 by nbuquet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>  // Todas las funciones pthread_*
# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <string.h>   // memset
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // write, usleep

# define MAX_PHILOS 200

typedef struct s_philo	t_philo;
typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					eating;
	int					meal_c;
	size_t				last_meal;
	size_t				start_time;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					number_of_philosophers;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					number_of_times_each_philosopher_must_eat;
	t_philo				*philos;
	int					dead;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		write_lock;
}						t_data;

// INITIALIZATION
void					init_data(t_data *data, t_philo *philos, char **av);
void					init_forks(pthread_mutex_t *forks,
							int number_of_philosophers);
void					init_philos(t_data *data, t_philo *philos,
							pthread_mutex_t *forks);

// THREADS
int						check_dead(t_philo *philo);
void					*routine(void *pointer);
int						thread_create(t_data *data, pthread_mutex_t *forks);

// ROUTINE
void					think(t_philo *philo);
void					dream(t_philo *philo);
void					eat(t_philo *philo);
void					print_routine(char *msg, t_philo *philo);

// MONITORING
void					*monitor(void *pointer);

// LIBFT UTILS
size_t					ft_strlen(const char *s);
int						ft_atoi(const char *nptr);
int						ft_isdigit(int c);

// ERROR UTILS
int						ft_error(char *msg);
void					clean_data(t_data *data, pthread_mutex_t *forks, char	*msg);
int						check_args(char **av);

// TIME UTILS
size_t					get_time(void);
int						ft_usleep(size_t milliseconds);

#endif