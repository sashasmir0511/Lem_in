/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:15:04 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:15:05 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	int		ants;
	t_rooms	*rooms;

	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms);
	solver(rooms, ants);
	ft_printf("\n");
	print_solver(rooms);
	rooms_del(rooms);
	return (0);
}
