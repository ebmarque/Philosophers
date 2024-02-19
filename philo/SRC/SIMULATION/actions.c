/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:45:50 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/19 16:07:28 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

void	_philo_sleep(t_philo *philo)
{
	_print_status(SLEEPING, philo);
	usleep(philo->time_to_sleep * 1000);
}

void	_eat(t_philo *philo)
{
	_print_status(EATING, philo);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->f_fork);
	pthread_mutex_unlock(philo->s_fork);
}

void	_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->f_fork);
	_print_status(FORK, philo);
	pthread_mutex_lock(philo->s_fork);
	_print_status(FORK, philo);
	_eat(philo);
}