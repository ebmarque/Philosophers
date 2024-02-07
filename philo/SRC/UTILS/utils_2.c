/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:39:53 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/07 18:00:12 by ebmarque         ###   ########.fr       */
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

int	_print_status(t_status status, long time_stamp, int id)
{
	printf("%ld ", time_stamp);
	if (status == THINKING)
		printf("%d is "YELLOW"thinking\n"RESET, id);
	else if (status == EATING)
		printf("%d is "GREEN"eating\n"RESET, id);
	else if (status == SLEEPING)
		printf("%d is "MAGENTA"sleeping\n"RESET, id);
	else if (status == DEAD)
		printf(RED"%d died\n"RESET, id);
	else if (status == FORK)
		printf("%d "BLUE"has taken a fork\n"RESET, id);
	else
		return (_error_message("ERROR: Wrong status code passed."));
	return (_error_message("ERROR: Wrong status code passed."));
}
