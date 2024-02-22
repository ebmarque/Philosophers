/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:26:13 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/22 10:25:38 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

int	_init_forks(t_table *table)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(table->write_permit, NULL) != 0)
		return (_error_message("ERROR: Failed to initialize mutex."));
	if (pthread_mutex_init(table->read_permit, NULL) != 0)
		return (_error_message("ERROR: Failed to initialize mutex."));
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
		if (pthread_create(&table->philo[i], NULL, _simulation, \
			&table->philo_data[i]) != 0)
			return (_error_message("ERROR: Fail to create threads."));
	}
	if (pthread_create(table->monitoring, NULL, _monitoring, table) != 0)
		return (_error_message("ERROR: Fail to create Monitoring thread."));
	return (0);
}

void	_join_and_destroy(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		pthread_join(table->philo[i], NULL);
		if (i < table->nb_philo / 2)
			pthread_mutex_destroy(&table->forks[i]);
	}
	pthread_join(*table->monitoring, NULL);
	pthread_mutex_destroy(table->read_permit);
	pthread_mutex_destroy(table->write_permit);
	_clean_all_data(table);
}
