/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:37:19 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 18:56:46 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->f_fork);
	_print_action(TOKE_FORK, philo);
	pthread_mutex_lock(philo->s_fork);
	_print_action(TOKE_FORK, philo);
}

void	_eat(t_philo *philo)
{
	_print_action(EATING, philo);
	_set_long(&philo->last_meal, philo->philo_data, \
		_precise_time() - philo->table->start_time);
	_precise_usleep(philo->time_eat);
	pthread_mutex_unlock(philo->f_fork);
	pthread_mutex_unlock(philo->s_fork);
	if (philo->meals >= 0 && philo->meals < philo->nb_meals)
		philo->meals++;
}

void	_sleep(t_philo *philo)
{
	_print_action(SLEEPING, philo);
	_precise_usleep(philo->time_sleep);
}

void	_go_think(t_philo *philo, bool pre_simulation)
{
	long	t_think;
	long	t_eat;
	long	t_sleep;

	if (!pre_simulation)
		_print_action(THINKING, philo);
	if (philo->table->nb_philos % 2 == 0)
		return ;
	t_eat = philo->table->time_eat;
	t_sleep = philo->table->time_sleep;
	t_think = (t_eat * 2) - t_sleep;
	if (t_think < 0)
		return ;
	_precise_usleep(t_think * 0.42);
}
