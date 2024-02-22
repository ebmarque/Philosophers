/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:08:09 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/22 10:21:03 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

bool	_is_dead(t_philo *philo, t_table *table)
{
	long	last_meal;
	long	t_die;
	long	start_time;

	start_time = _get_long(&table->start_time, table->read_permit);
	last_meal = _get_long(&philo->last_meal_time, table->read_permit);
	t_die = _get_long(&table->time_to_die, table->read_permit);
	if (t_die < (_precise_time(MILISECOND) - start_time) - last_meal)
	{
		_print_status(DEAD, philo);
		return (true);
	}
	return (false);
}

void	*_monitoring(void *data)
{
	int		i;
	int		counter;
	t_table	*table;

	i = -1;
	counter = 0;
	table = (t_table *)data;
	while (_simulation_status(table))
	{
		if (++i == table->nb_philo)
		{
			i = 0;
			counter = 0;
		}
		if (_is_dead(&table->philo_data[i], table))
			_set_bool(&table->simulation, table->write_permit, false);
		if (table->philo_data[i].satisfied == true)
			counter++;
		if (counter == table->nb_philo)
		{
			_set_bool(&table->simulation, table->write_permit, false);
			printf(GREEN"All philosophers are satisfied!\n"RESET);
		}
	}
	return (NULL);
}
