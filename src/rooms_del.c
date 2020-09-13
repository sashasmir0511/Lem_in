/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:13:06 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/13 14:12:30 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	rooms_del(t_rooms *rooms)
{
	int		i;
	t_room	*tmp;

	if (rooms->head_paths)
		paths_del(rooms);
	while (rooms->room_list)
	{
		tmp = rooms->room_list;
		rooms->room_list = rooms->room_list->room_list;
		room_del(tmp);
	}
	i = 0;
	while (rooms->table_name != NULL && i < rooms->num_of_rooms)
	{
		free(rooms->table_paths[i]);
		free(rooms->table_name[i]);
		i++;
	}
	free(rooms->table_paths);
	free(rooms->table_name);
	free(rooms);
}
