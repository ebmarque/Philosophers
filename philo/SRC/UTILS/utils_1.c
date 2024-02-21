/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:54:33 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/21 14:13:31 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

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

void	_put_str_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		*p = '\0';
		p++;
		i++;
	}
}

int	_error_message(char *str)
{
	printf(RED"%s\n"RESET, str);
	return (-1);
}

long	_get_long(long *value, t_mutex *mutex)
{
	long	long_value;

	pthread_mutex_lock(mutex);
	long_value = *value;
	pthread_mutex_unlock(mutex);
	return (long_value);
}