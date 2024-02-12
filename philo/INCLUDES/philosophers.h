/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:29:02 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/12 14:24:51 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

// Color codes
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"

typedef enum e_timecode
{
	SECOND,
	MILISECOND,
	MICROSECOD,
}			t_timecode;
typedef enum e_status
{
	FORK,
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}			t_status;

typedef struct s_mutex
{
	pthread_mutex_t	*fork;
	int				id;
}			t_mutex;

typedef struct s_philo
{
	t_mutex	*r_fork;
	t_mutex	*l_fork;
	t_mutex	*write_permit;
	long	number_of_meals;
	long	last_meal_time;
	bool	satisfied;
	bool	alive;
	bool	*simulation;
	int		id;
}			t_philo;

typedef struct s_table
{
	pthread_t	*monitoring;
	pthread_t	*philo;
	t_philo		*philo_data;
	t_mutex		*forks;
	t_mutex		*write_permit;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		number_of_meals;
	int			nb_philo;
	bool		simulation;
}				t_table;

// UTILS_1
int		_error_message(char *str);
long	_atol(char *str);
void	_put_str_fd(char *str, int fd);
void	ft_bzero(void *s, size_t n);

// UTILS_2
int		_print_status(t_status status, long time_stamp, int id);
long	_precise_time(t_timecode time_code);

// INIT
void	_fork_assignment(t_table *table, int i);
void	_init_philo(t_table *table);
int		_init_table(t_table *table, int argc, char **argv);

// ERRORS
int		_is_valid_input(int argc, char *argv[]);
bool	_invalid_char(int argc, char **argv);

#endif