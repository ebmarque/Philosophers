/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:31:22 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/19 15:59:32 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	(void)table;
	if (_is_valid_input(argc, argv) == 0)
	{
		if (_init_table(&table, argc, argv) != 0)
		{
			return (0);
		}
		_start_simulation(&table);
	}
	return (0);
}
