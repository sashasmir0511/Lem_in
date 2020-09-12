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
	char	*map;

	rooms = NULL;
	map = NULL;
	ants = get_ants(&map);
	if (rooms_add(&rooms, &map))
		error(rooms, NULL, map);
	solver(rooms, ants);
	ft_printf("%s\n", map);
	print_solver(rooms);
	rooms_del(rooms);
	free(map);
	return (0);
}
