/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:16:21 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/21 17:45:35 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

void	_precise_usleep(long usec, t_table *table)
{
	long	start;
	long	elapsed;
	long	rem;

	start = _precise_time(MILISECOND);
	rem = 0;
	elapsed = 0;
	while (_precise_time(MILISECOND) - start < usec)
	{
		if (_simulation_status(table) == false)
			break;
		elapsed = _precise_time(MILISECOND) - start;
		rem = usec - elapsed;
		if (rem > 1e3)
			usleep(rem / 2);
		else
		{
			while (_precise_time(MILISECOND) - start < usec)
				;
		}
	}
	
}

bool	_simulation_status(t_table *table)
{
	return (_get_bool(&table->simulation, table->read_permit));
}

void	_clean_all_data(t_table *table)
{
	if (table->philo)
		free(table->philo);
	if (table->philo_data)
		free(table->philo_data);
	if (table->forks)
		free(table->forks);
	if (table->write_permit)
		free(table->write_permit);
	if (table->read_permit)
		free(table->read_permit);
	if (table->monitoring)
		free(table->monitoring);	
}