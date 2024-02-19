/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:37:22 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/19 16:12:35 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

void	_wait_simulation_start(t_philo *philo)
{
	while (philo->simulation == false)
		;
}

void	*_monitoring_thread(void *data)
{
	t_table	*table;
	int		i;

	i = 0;
	table = (t_table *)data;
	while (i < table->nb_philo)
	{
		if (table->philo_data[i + 1].alive == false)
			table->simulation = false;
		i++;
		if (i == table->nb_philo)
			i = 0;
	}
	return (0);
}

void	*_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	_wait_simulation_start(philo);
	while (*philo->simulation)
	{
		philo->start_action = _precise_time(MICROSECOD);
		_print_status(THINKING, philo);
		_take_forks(philo);
		_philo_sleep(philo);
		if (!*philo->simulation)
			break ;
	}
	return (0);
}
int	_start_simulation(t_table *table)
{
	if (_init_forks(table) == 0)
		if (_create_threads(table) == 0)
			table->simulation = true;
	sleep(3);
	table->simulation = false;
	_join_and_destroy(table);
	return (0);
}
