/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:26:13 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/12 14:26:49 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

int	_init_forks(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (_error_message("ERROR: Failed to initialize mutex."));
	}
	return (0);
}

int	_create_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		if (pthread_create(table->philo[i], NULL, _simulation, \
			&table->philo[i]) != 0)
			return (_error_message("ERROR: Fail to create threads."));
	}
	return (0);
}

int	_start_simulation(t_table *table)
{
	if (_init_forks(table) == 0)
		if (_create_threads(table) == 0)
		{
			table->simulation = true;
			if (_start_monitoring(table) == -1)
				_finish_simulation(table);
		}

	return (0);
}
