/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:59:01 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 18:57:52 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	_init_mutexes(t_table *table)
{
	long	i;

	i = -1;
	while (++i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (_error_message("ERROR: Failed to initialize mutex."));
		if (pthread_mutex_init(&table->philo_data[i], NULL) != 0)
			return (_error_message("ERROR: Failed to initialize mutex."));
	}
	if (pthread_mutex_init(&table->printer, NULL) != 0)
		return (_error_message("ERROR: Failed to initialize mutex."));
	if (pthread_mutex_init(&table->table_data, NULL) != 0)
		return (_error_message("ERROR: Failed to initialize mutex."));
	return (0);
}

int	_init_threads(t_table *table)
{
	long	i;

	i = -1;
	if (table->nb_philos == 1)
	{
		if (pthread_create(&table->p_threads[0], NULL, \
			_one_philo, &table->philo[0]) != 0)
			return (_error_message("ERROR: Failed to create thread."));
	}
	else
	{
		while (++i < table->nb_philos)
		{
			if (pthread_create(&table->p_threads[i], NULL, \
				_simulation, &table->philo[i]) != 0)
				return (_error_message("ERROR: Failed to create thread."));
		}
	}
	if (table->nb_philos > 1 && pthread_create(&table->s_thread, NULL, \
			_monitoring, table) != 0)
		return (_error_message("ERROR: Failed to create monitor thread."));
	table->start_time = _precise_time();
	_set_bool(&table->simulation, &table->table_data, true);
	return (0);
}
