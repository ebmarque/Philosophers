/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:31:22 by ebmarque          #+#    #+#             */
/*   Updated: 2024/02/06 12:42:58 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/philosophers.h"

bool	_is_valid_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (false);
	
	return (true);
}


int main(int argc, char *argv[])
{
	

	if (_is_valid_input(argc, argv))\
	{
		
	}
	
	return (0);
}
