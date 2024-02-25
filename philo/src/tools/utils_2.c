/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:48:29 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/23 19:13:52 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

bool	_get_bool(bool *value, t_mutex *mutex)
{
	bool	result;

	pthread_mutex_lock(mutex);
	result = *value;
	pthread_mutex_unlock(mutex);
	return (result);
}

long	_get_long(long *value, t_mutex *mutex)
{
	long	result;

	pthread_mutex_lock(mutex);
	result = *value;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	_set_bool(bool *variable, t_mutex *mutex, bool value)
{
	pthread_mutex_lock(mutex);
	*variable = value;
	pthread_mutex_unlock(mutex);
}

void	_set_long(long *variable, t_mutex *mutex, long value)
{
	pthread_mutex_lock(mutex);
	*variable = value;
	pthread_mutex_unlock(mutex);
}

void	_increase_long(long *variable, t_mutex *mutex)
{
	pthread_mutex_lock(mutex);
	*variable += 1;
	pthread_mutex_unlock(mutex);
}
