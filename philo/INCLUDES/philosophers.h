/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:29:02 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/06 12:42:48 by ebmarque         ###   ########.fr       */
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

typedef struct s_philo
{
	long	time_to_die;
	long	time_to_sleep;
	long	time_to_think;
	long	number_of_meals;
	bool	alive;
	bool	satisfied;
	int		id;
}			t_philo;

// UTILS_1
long	_atol(char *str);
size_t	_strlen(char *str);
void	_put_str_fd(char *str, int fd);




#endif