/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:09:37 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 18:57:10 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	_wait_all_threads(t_table *table)
{
	while (!_simulation_status(table))
		;
}

void	*_monitoring(void *data)
{
	t_table	*table;
	long	i;

	i = -1;
	table = (t_table *)data;
	_wait_all_threads(table);
	_precise_usleep(60);
	while (table->simulation)
	{
		while (++i < table->nb_philos)
		{
			if (_check_full(table))
				return (NULL);
			if ((_precise_time() - table->start_time) - \
				table->philo[i].last_meal > table->time_die)
			{
				_print_action(DIED, &table->philo[i]);
				_set_bool(&table->simulation, &table->table_data, false);
				return (NULL);
			}
		}
		i = -1;
	}
	return (NULL);
}

void	*_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	_wait_all_threads(philo->table);
	_de_syncronize(philo);
	while (_simulation_status(philo->table))
	{
		_take_forks(philo);
		_eat(philo);
		_sleep(philo);
		_go_think(philo, false);
	}
	return (NULL);
}

void	*_one_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	_print_action(TOKE_FORK, philo);
	_precise_usleep(philo->time_die);
	_print_action(DIED, philo);
	return (NULL);
}
