/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:39:53 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/22 12:23:54 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

long	_precise_time(t_timecode time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (_error_message("Error: Function 'gettimeofday failed.\n"));
	if (SECOND == time_code)
		return ((tv.tv_sec + (tv.tv_usec / 1e6)));
	if (MILISECOND == time_code)
		return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
	if (MICROSECOD == time_code)
		return ((tv.tv_sec * 1e6) + (tv.tv_usec));
	return (_error_message("ERROR: Wrong time code passed to 'precise_time'"));
}

int	_print_status(t_status status, t_philo *philo)
{
	long	time_stamp;

	pthread_mutex_lock(philo->table->write_permit);
	time_stamp = _precise_time(MILISECOND) - \
		_get_long(&philo->table->start_time, philo->table->read_permit);
	if (status == THINKING && _simulation_status(philo->table))
		printf("%ld %ld is "YELLOW"thinking\n"RESET, time_stamp, philo->id);
	else if (status == EATING && _simulation_status(philo->table))
		printf("%ld %ld is "GREEN"eating\n"RESET, time_stamp, philo->id);
	else if (status == SLEEPING && _simulation_status(philo->table))
		printf("%ld %ld is "MAGENTA"sleeping\n"RESET, time_stamp, philo->id);
	else if (status == DEAD && _simulation_status(philo->table))
		printf(RED"%ld %ld died\n"RESET, time_stamp, philo->id);
	else if (status == FORK && _simulation_status(philo->table))
		printf("%ld %ld "BLUE"has taken a fork\n"RESET, time_stamp, philo->id);
	else if (status == AWAITING)
		printf("%ld %ld "BLUE"IS WAITING TO BEGIN\n"RESET, time_stamp, philo->id);
	pthread_mutex_unlock(philo->table->write_permit);
	return (0);
}

bool	_get_bool(bool *value, t_mutex *mutex)
{
	bool	bool_value;

	pthread_mutex_lock(mutex);
	bool_value = *value;
	pthread_mutex_unlock(mutex);
	return (bool_value);
}

void	_set_bool(bool *variable, t_mutex *mutex, bool value)
{
	pthread_mutex_lock(mutex);
	*variable = value;
	pthread_mutex_unlock(mutex);
}

void	_set_long(long *variable, t_mutex *mutex, long value)
{
	pthread_mutex_lock(mutex);
	*variable = value;
	pthread_mutex_unlock(mutex);
}
