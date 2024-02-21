/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:37:22 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/21 23:04:52 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

void	_wait_simulation_start(t_philo *philo)
{
	while (!_simulation_status(philo->table))
		;
}


void	*_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	_wait_simulation_start(philo);
	if(philo->id % 2 == 0)
		_precise_usleep(10, philo->table);
	_set_long(&philo->table->start_time, philo->table->write_permit, \
			_precise_time(MILISECOND));
	while (_simulation_status(philo->table))
	{
		_take_forks(philo);
		_philo_sleep(philo);
		_print_status(THINKING, philo);
		if (!_simulation_status(philo->table))
			break ;
	}
	return (0);
}
int	_start_simulation(t_table *table)
{
	if (_init_forks(table) == 0)
		if (_create_threads(table) == 0)
			_set_bool(&table->simulation, table->write_permit, true);
	_join_and_destroy(table);
	return (0);
}
