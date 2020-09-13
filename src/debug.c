/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:13:26 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:13:27 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	room_print(t_room *room)
{
	if (room == NULL)
		return ;
	ft_printf("name_room -> %s\n", room->name);
	ft_printf("x -> %d y -> %d\n", room->coord_x, room->coord_y);
	ft_printf("status -> %d\n", room->status);
}

void	print_path(t_path *p)
{
	int i;

	i = 0;
	ft_printf("size - %d: ", p->size_path);
	while (i < p->size_path)
	{
		ft_printf("%d ", p->path[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_paths(t_rooms *rooms)
{
	t_path	*p;
	t_ant	*a;

	p = rooms->head_paths;
	ft_printf("___________\n");
	while (p)
	{
		print_path(p);
		a = p->ant_head;
		while (a)
		{
			ft_printf("ant -> %d, index_room -> %d\n",
				a->index, a->index_room);
			a = a->next;
		}
		p = p->next;
	}
	ft_printf("___________\n");
}

void	table_print(t_rooms *rooms)
{
	int	i;
	int j;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		j = 0;
		ft_printf("%s", rooms->table_name[i]);
		while (j < rooms->num_of_rooms)
		{
			ft_printf(" %d", rooms->table_paths[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	debug(int ants, t_rooms *rooms)
{
	ft_printf("\nant -> %d\n", ants);
	ft_printf("num_of_room -> %d\n", rooms->num_of_rooms);
	ft_printf("start -> %s(%d)\tend -> %s(%d)\n",
		rooms->table_name[rooms->start], rooms->start,
		rooms->table_name[rooms->end], rooms->end);
	ft_printf("----------------\n");
	table_print(rooms);
	print_paths(rooms);
}
