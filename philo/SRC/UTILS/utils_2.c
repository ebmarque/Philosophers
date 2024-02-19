/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:39:53 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/19 13:05:19 by ebmarque         ###   ########.fr       */
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

	time_stamp = _precise_time(MILISECOND) - philo->start_time;
	pthread_mutex_lock(philo->write_permit);
	if (status == THINKING)
		printf("%ld %d is "YELLOW"thinking\n"RESET, time_stamp, philo->id);
	else if (status == EATING)
		printf("%ld %d is "GREEN"eating\n"RESET, time_stamp, philo->id);
	else if (status == SLEEPING)
		printf("%ld %d is "MAGENTA"sleeping\n"RESET, time_stamp, philo->id);
	else if (status == DEAD)
		printf(RED"%ld %d died\n"RESET, time_stamp, philo->id);
	else if (status == FORK)
		printf("%ld %d "BLUE"has taken a fork\n"RESET, time_stamp, philo->id);
	else
	{
		pthread_mutex_unlock(philo->write_permit);
 		return (_error_message("ERROR: Wrong status code passed."));
	}
	pthread_mutex_unlock(philo->write_permit);
	return (0);
}
