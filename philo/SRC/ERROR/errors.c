/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:04:59 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/06 15:05:03 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

bool	_invalid_char(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (++i < argc)
	{
		if (!argv[i] || !*argv[i])
			return (true);
		while (argv[i][j])
		{
			if (argv[i][j] == '+' && j == 0 && argv[i][j + 1] != '\0')
				j++;
			else if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				break ;
		}
		if (argv[i][j] != '\0')
			return (true);
		j = 0;
	}
	return (false);
}

bool	_is_valid_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		_put_str_fd(RED"ERROR: Invalid number of arguments!\n"RESET, 2);
		return (false);	
	}
	if (_invalid_char(argc, argv))
	{
		_put_str_fd(RED"ERROR: Invalid argument!\n"RESET, 2);
		return (false);
	}
	return (true);
}
