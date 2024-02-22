/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:45:50 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/22 12:22:26 by ebmarque         ###   ########.fr       */
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
	_print_status(EATING, philo);
	_set_long(&philo->last_meal_time, philo->table->write_permit, \
		_precise_time(MILISECOND) - _get_long(&philo->table->start_time, \
		philo->table->read_permit));
	_precise_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(philo->f_fork);
	pthread_mutex_unlock(philo->s_fork);
	philo->meals++;
	if (philo->table->number_of_meals > 0 && (_get_long(&philo->meals, \
		philo->table->read_permit) >= philo->table->number_of_meals))
		philo->satisfied = true;
}

void	_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->f_fork);
	_print_status(FORK, philo);
	pthread_mutex_lock(philo->s_fork);
	_print_status(FORK, philo);
	_eat(philo);
}
