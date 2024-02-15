/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:26:13 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/15 12:21:55 by ebmarque         ###   ########.fr       */
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

void	_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->write_permit);
	_print_status(EATING, _precise_time(MILISECOND) - philo->start_time, philo->id);
	usleep(1000);
	pthread_mutex_unlock(philo->write_permit);
	pthread_mutex_unlock(philo->f_fork);
	pthread_mutex_unlock(philo->s_fork);
	usleep(1);
}

void	_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->f_fork);
	pthread_mutex_lock(philo->write_permit);
	_print_status(FORK, _precise_time(MILISECOND) - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->write_permit);
	pthread_mutex_lock(philo->s_fork);
	pthread_mutex_lock(philo->write_permit);
	_print_status(FORK, _precise_time(MILISECOND) - philo->start_time, philo->id);
	pthread_mutex_unlock(philo->write_permit);
	_eat(philo);
	/* pthread_mutex_unlock(philo->f_fork);
	pthread_mutex_unlock(philo->s_fork); */
}
void	*_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	_wait_simulation_start(philo);
	while (*philo->simulation)
	{
		_take_forks(philo);
		// _sleep(philo);
		if (!*philo->simulation)
			break ;
	}
	return (0);
}

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
		if (pthread_create(&table->philo[i], NULL, _simulation, \
			&table->philo_data[i]) != 0)
			return (_error_message("ERROR: Fail to create threads."));
	}
	/* if (pthread_create(table->monitoring, NULL, _monitoring_thread, table) != 0)
		return (_error_message("ERROR: Fail to create monitoring thread.")); */
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
