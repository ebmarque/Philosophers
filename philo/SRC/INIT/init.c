/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:54:21 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/06 15:54:39 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

void	_init_philo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		table->philo_data[i].time_to_die = table->time_to_die;
		table->philo_data[i].time_to_eat = table->time_to_eat;
		table->philo_data[i].time_to_sleep = table->time_to_sleep;
		table->philo_data[i].number_of_meals = table->number_of_meals;
		table->philo_data[i].alive = true;
		table->philo_data[i].satisfied = false;
		table->philo_data[i].id = i + 1;
	}
}

void	_init_table(t_table *table, int argc, char **argv)
{
	ft_bzero((void)table, sizeof(t_table));
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
		table->philo = (pthread_t *)malloc(sizeof(pthread_t) * \
			table->nb_philo);
		if (!table->philo_data || !table->philo)
		{
			_put_str_fd(RED"ERROR: Memory allocation failed!\n"RESET, 2);
			exit(1);
		}
		_init_philo(table);
	}
}
