/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:45:50 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/21 18:35:16 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

void	_philo_sleep(t_philo *philo)
{
	_print_status(SLEEPING, philo);
	_precise_usleep(philo->table->time_to_sleep, philo->table);
}

void	_eat(t_philo *philo)
{
	_set_long(&philo->last_meal_time, philo->table->write_permit, \
		_precise_time(MILISECOND) - _get_long(&philo->table->start_time, \
		philo->table->read_permit));
	_print_status(EATING, philo);
	_precise_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(philo->f_fork);
	pthread_mutex_unlock(philo->s_fork);
	_set_long(&philo->meals, philo->table->write_permit, \
		_get_long(&philo->meals, philo->table->read_permit) + 1);
	if (philo->table->number_of_meals > 0 && (_get_long(&philo->meals, \
		philo->table->read_permit) >= philo->table->number_of_meals ))
		_set_bool(&philo->satisfied, philo->table->write_permit, true);
	printf("PHILO : %ld is satisfied: %d\n", philo->id, _get_bool(&philo->satisfied, philo->table->read_permit));
}

void	_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->f_fork);
	_print_status(FORK, philo);
	pthread_mutex_lock(philo->s_fork);
	_print_status(FORK, philo);
	_eat(philo);
}