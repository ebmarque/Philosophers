/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:08:09 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/21 18:42:30 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

bool	_is_dead(t_philo *philo, t_table *table)
{
	int i;
	
	i = 2 * 4;
	(void)philo;
	(void)table;
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
			_set_bool(&table->simulation, table->write_permit, false);
		// printf("counter: %d\n", counter);
	}
	return (NULL);
}
