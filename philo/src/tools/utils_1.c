/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:46:14 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 18:58:58 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long	_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (!str | !*str)
		return (0);
	while ((*str && *str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	_error_message(char *str)
{
	printf(RED"%s\n", str);
	return (-1);
}

void	_print_action(t_status status, t_philo *philo)
{
	long	time_stamp;

	pthread_mutex_lock(&philo->table->printer);
	time_stamp = _precise_time() - \
		_get_long(&philo->table->start_time, &philo->table->table_data);
	if (status == THINKING && _simulation_status(philo->table))
		printf(YELLOW"%ld %ld is thinking\n"RESET, time_stamp, philo->id);
	else if (status == EATING && _simulation_status(philo->table))
	{
		philo->last_meal = _precise_time() - philo->table->start_time;
		printf(GREEN"%ld %ld is eating\n"RESET, time_stamp, philo->id);
	}
	else if (status == SLEEPING && _simulation_status(philo->table))
		printf(CYAN"%ld %ld is sleeping\n"RESET, time_stamp, philo->id);
	else if (status == DIED && _simulation_status(philo->table))
		printf(RED"%ld %ld died\n"RESET, time_stamp, philo->id);
	else if (status == TOKE_FORK && _simulation_status(philo->table))
		printf("%ld %ld has taken a fork\n", time_stamp, philo->id);
	pthread_mutex_unlock(&philo->table->printer);
}

void	_join_and_destroy(t_table *table)
{
	int	i;

	i = -1;
	if (table->nb_philos == 1)
		pthread_join(table->p_threads[0], NULL);
	else
	{
		while (++i < table->nb_philos)
		{
			pthread_join(table->p_threads[i], NULL);
			pthread_mutex_destroy(&table->forks[i]);
			pthread_mutex_destroy(&table->philo_data[i]);
		}
		pthread_join(table->s_thread, NULL);
	}
	pthread_mutex_destroy(&table->printer);
	pthread_mutex_destroy(&table->table_data);
}

bool	_check_full(t_table *table)
{
	long	i;

	i = -1;
	while (++i < table->nb_philos)
	{
		if (table->nb_meals == -1 || (table->philo[i].meals != table->nb_meals))
			return (false);
	}
	pthread_mutex_lock(&table->printer);
	printf(BLUE"All philos are full\n"RESET);
	_set_bool(&table->simulation, &table->table_data, false);
	pthread_mutex_unlock(&table->printer);
	return (true);
}
