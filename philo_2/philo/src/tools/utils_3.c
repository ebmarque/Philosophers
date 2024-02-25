/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:16:18 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 17:04:25 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

bool	_simulation_status(t_table *table)
{
	return (_get_bool(&table->simulation, &table->table_data));
}

long	_precise_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (_error_message("Error: Function 'gettimeofday failed.\n"));
	return ((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3));
}

void	_precise_usleep(long milliseconds)
{
	long	start;

	start = _precise_time();
	while ((_precise_time() - start) < milliseconds)
		usleep(500);
}

void	_de_syncronize(t_philo *philo)
{
	if (philo->table->nb_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			_precise_usleep(10);
	}
	else
	{
		if (philo->id % 2 != 0)
			_go_think(philo, true);
	}
}

void	_clean_all_data(t_table *table)
{
	if (table->forks)
		free(table->forks);
	if (table->philo)
		free(table->philo);
	if (table->philo_data)
		free(table->philo_data);
	if (table->p_threads)
		free(table->p_threads);
}
