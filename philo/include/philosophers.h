/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:31:19 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 19:04:00 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

// Color codes
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

typedef pthread_mutex_t	t_mutex;

typedef enum e_status
{
	DIED,
	EATING,
	SLEEPING,
	THINKING,
	TOKE_FORK
}	t_status;

typedef struct s_philo
{
	struct s_table	*table;
	t_mutex			*f_fork;
	t_mutex			*s_fork;
	t_mutex			*philo_data;
	long			time_die;
	long			time_eat;
	long			time_sleep;
	long			last_meal;
	long			nb_meals;
	long			id;
	long			meals;
	bool			alive;
}	t_philo;

typedef struct s_table
{
	t_philo		*philo;
	pthread_t	*p_threads;
	pthread_t	s_thread;
	t_mutex		printer;
	t_mutex		table_data;
	t_mutex		*philo_data;
	t_mutex		*forks;
	long		time_die;
	long		time_eat;
	long		time_sleep;
	long		nb_philos;
	long		nb_meals;
	long		philo_satisfied;
	long		start_time;
	bool		simulation;
}	t_table;

// INPUT_VALIDATION
int		_is_valid_input(int argc, char *argv[]);
bool	_invalid_char(int argc, char **argv);
int		_verify_zero_values(int argc, char **argv);

// DATA_INITIALIZATION
void	_fork_assignment(t_philo *philo, t_table *table);
int		_init_philo_data(t_table *table);
int		_table_init_data(t_table *table, int argc, char **argv);

// INIT_SIMULATION
int		_init_mutexes(t_table *table);
int		_init_threads(t_table *table);

// SIMULATION
void	*_monitoring(void *data);
void	*_simulation(void *data);
void	_wait_all_threads(t_table *table);
void	*_one_philo(void *data);

// ACTIONS
void	_take_forks(t_philo *philo);
void	_eat(t_philo *philo);
void	_sleep(t_philo *philo);
void	_go_think(t_philo *philo, bool pre_simulation);

// UTILS_1
long	_atol(char *str);
int		_error_message(char *str);
void	_print_action(t_status status, t_philo *philo);
void	_join_and_destroy(t_table *table);
bool	_check_full(t_table *table);

// UTILS_2
bool	_get_bool(bool *value, t_mutex *mutex);
long	_get_long(long *value, t_mutex *mutex);
void	_set_bool(bool *variable, t_mutex *mutex, bool value);
void	_set_long(long *variable, t_mutex *mutex, long value);
void	_increase_long(long *variable, t_mutex *mutex);

// UTILS_3
void	_precise_usleep(long milliseconds);
long	_precise_time(void);
bool	_simulation_status(t_table *table);
void	_de_syncronize(t_philo *philo);
void	_clean_all_data(t_table *table);

#endif