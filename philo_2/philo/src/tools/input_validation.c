/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:06:39 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 19:13:49 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

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
			if (argv[i][j + 1] != '\0' && argv[i][j] == '+' && j == 0)
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

int	_verify_zero_values(int argc, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	while (++i < argc)
	{
		nbr = _atol(argv[i]);
		if (nbr <= 0)
			return (_error_message("NULL values are not aceptable!"));
		else if (nbr > INT_MAX)
			return (_error_message("Values over INT_MAX are not aceptable!"));
		else if (nbr > 200 && i == 1)
			return (_error_message("ERROR: More than 200 philosophers."));
		else if (nbr < 60 && i > 1 && i < 5)
			return (_error_message("ERROR: Less than 60ms is not aceptable!"));
	}
	return (0);
}

int	_is_valid_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (_error_message("ERROR: Invalid number of arguments."));
	if (_invalid_char(argc, argv))
		return (_error_message(("ERROR: Invalid argument.")));
	return (_verify_zero_values(argc, argv));
}
