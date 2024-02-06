/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:31:22 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/06 15:05:11 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	if (_is_valid_input(argc, argv))\
	{
		printf("Valid input\n");
	}
	
	return (0);
}
