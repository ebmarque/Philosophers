/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:44:37 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 18:58:31 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	_fork_assignment(t_philo *philo, t_table *table)
{
	if (philo->id % 2 == 0)
	{
		philo->f_fork = &table->forks[philo->id - 1];
		philo->s_fork = &table->forks[philo->id % table->nb_philos];
	}
	else
	{
		philo->f_fork = &table->forks[philo->id % table->nb_philos];
		philo->s_fork = &table->forks[philo->id - 1];
	}
}

int	_init_philo_data(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philos)
	{
		table->philo[i].id = i + 1;
		table->philo[i].alive = true;
		if (table->nb_meals > 0)
			table->philo[i].meals = 0;
		else
			table->philo[i].meals = -1;
		table->philo[i].last_meal = 0;
		table->philo[i].nb_meals = table->nb_meals;
		table->philo[i].time_die = table->time_die;
		table->philo[i].time_eat = table->time_eat;
		table->philo[i].time_sleep = table->time_sleep;
		table->philo[i].table = table;
		table->philo[i].philo_data = &table->philo_data[i];
		_fork_assignment(&table->philo[i], table);
	}
	return (0);
}

int	_table_init_data(t_table *table, int argc, char **argv)
{
	table->simulation = false;
	table->start_time = 0;
	table->nb_philos = _atol(argv[1]);
	table->time_die = _atol(argv[2]);
	table->time_eat = _atol(argv[3]);
	table->time_sleep = _atol(argv[4]);
	table->forks = (t_mutex *)malloc(table->nb_philos * sizeof(t_mutex));
	table->philo_data = (t_mutex *)malloc(table->nb_philos * sizeof(t_mutex));
	table->philo = (t_philo *)malloc(table->nb_philos * sizeof(t_philo));
	table->p_threads = \
		(pthread_t *)malloc(table->nb_philos * sizeof(pthread_t));
	if (!table->forks || !table->philo || \
		!table->p_threads || !table->philo_data)
		return (_error_message("ERROR: Failed to allocate memory."));
	if (argc == 6)
		table->nb_meals = _atol(argv[5]);
	else
	{
		table->philo_satisfied = -1;
		table->nb_meals = -1;
	}
	return (_init_philo_data(table));
}
