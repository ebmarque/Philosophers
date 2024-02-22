/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:37:22 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/22 12:34:49 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

static void	_go_think(t_philo *philo, t_table *table)
{
	long	last_meal;
	long	t_die;
	long	start_time;
	long	rem;

	_print_status(THINKING, philo);
	start_time = _get_long(&table->start_time, table->read_permit);
	last_meal = _get_long(&philo->last_meal_time, table->read_permit);
	t_die = _get_long(&table->time_to_die, table->read_permit);
	rem = t_die - (_precise_time(MILISECOND) - start_time) - last_meal;
	// printf("philo: %ld has %ld miliseconds to die\n", philo->id, rem);
	if (rem > 2e3)
		_precise_usleep(10, table);
}

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
	if (philo->id % 2 == 0)
		_precise_usleep(30, philo->table);
	while (_simulation_status(philo->table))
	{
		_take_forks(philo);
		_philo_sleep(philo);
		// _print_status(THINKING, philo);
		_go_think(philo, philo->table);
		if (!_simulation_status(philo->table))
			break ;
	}
	return (0);
}

int	_start_simulation(t_table *table)
{
	if (_init_forks(table) == 0)
		if (_create_threads(table) == 0)
		{
			table->start_time = _precise_time(MILISECOND);
			printf(GREEN" --------------------> ALL THREADS CREATED <----------------------\n\n"RESET);
			_set_bool(&table->simulation, table->write_permit, true);
		}
	_join_and_destroy(table);
	return (0);
}
