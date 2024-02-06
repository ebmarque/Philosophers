/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:54:33 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/06 12:42:32 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

long	_atol(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 0;
	if (!str | !*str)
		return (0);
	while (*str && (*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && (*str >= 0 && *str <= 9))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
size_t	_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
		i++;
	return (i);
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