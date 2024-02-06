/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:29:02 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/06 15:57:48 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIHLOSOPHER_H
# define PIHLOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <limits.h>
# include <stdbool.h>

// Color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

enum e_status
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
};

typedef struct s_philo
{
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	number_of_meals;
	bool	alive;
	bool	satisfied;
	int		id;
}			t_philo;

typedef struct s_table
{
	t_philo		*philo_data;
	pthread_t	*philo;
	int			nb_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		number_of_meals;
}				t_table;

// UTILS_1
long	_atol(char *str);
size_t	_strlen(char *str);
void	_put_str_fd(char *str, int fd);
bool	_is_valid_input(int argc, char *argv[]);
void	ft_bzero(void *s, size_t n);

// UTILS_2

// INIT
void	_init_philo(t_table *table);
void	_init_table(t_table *table, int argc, char **argv);

#endif