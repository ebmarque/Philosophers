/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:51:40 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/25 18:57:25 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (_is_valid_input(argc, argv) == 0)
	{
		if (_table_init_data(&table, argc, argv) == 0)
		{
			if (_init_mutexes(&table) == 0)
				if (_init_threads(&table) == 0)
					_join_and_destroy(&table);
		}
		_clean_all_data(&table);
	}
	return (0);
}
