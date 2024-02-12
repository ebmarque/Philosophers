/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:54:21 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/12 14:24:19 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

/**
 * This function aims to create contentions areas in the
 * fork assignment to avoid deadlocks. The work arround here is in which fork 
 * the philosopher goes first, if the philosopher ID is even, he should grab
 * first the right fork, else, he should grab the left fork first.
 */
void	_fork_assignment(t_table *table, int i)
{
	if (table->philo_data[i].id % 2 == 0)
	{
		table->philo_data->r_fork = &table->forks[i];
		table->philo_data->l_fork = &table->forks[(i + 1) % table->nb_philo];
	}
	else
	{
		table->philo_data->l_fork = &table->forks[(i + 1) % table->nb_philo];
		table->philo_data->r_fork = &table->forks[i];
	}
}

void	_init_philo(t_table *table)
{
	int	i;

	i = -1;
	ft_bzero(table->philo_data, sizeof(t_philo));
	ft_bzero(table->forks, sizeof(t_fork));
	while (++i < table->nb_philo)
	{
		table->philo_data[i].number_of_meals = table->number_of_meals;
		table->philo_data[i].alive = true;
		table->philo_data[i].satisfied = false;
		table->philo_data[i].id = i + 1;
		table->philo_data[i].simulation = &table->simulation;
		table->philo_data[i].write_permit = &table->write_permit;
		_fork_assignment(table, i);
	}
}

int	_init_table(t_table *table, int argc, char **argv)
{
	ft_bzero(table, sizeof(t_table));
	if (_is_valid_input(argc, argv))
	{
		table->nb_philo = _atol(argv[1]);
		table->time_to_die = _atol(argv[2]);
		table->time_to_eat = _atol(argv[3]);
		table->time_to_sleep = _atol(argv[4]);
		if (argc == 6)
			table->number_of_meals = _atol(argv[5]);
		else
			table->number_of_meals = -1;
		table->philo_data = (t_philo *)malloc(sizeof(t_philo) * \
			table->nb_philo);
		table->monitoring = (pthread_t *)malloc(sizeof(pthread_t));
		table->philo = (pthread_t *)malloc(sizeof(pthread_t) * table->nb_philo);
		table->forks = (t_mutex *)malloc(sizeof(t_mutex) * table->nb_philo);
		table->write_permit = (t_mutex *)malloc(sizeof(t_mutex));
		table->simulation = (bool *)malloc(sizeof(bool));
		if (!table->philo_data || !table->philo || !table->forks \
			|| !table->write_permit || !table->simulation || !table->monitoring)
			return (_error_message("ERROR: Memory allocation failed."));
		_init_philo(table);
	}
	return (0);
}
