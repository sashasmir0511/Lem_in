/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:15:41 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:15:43 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		delete_paths_from_table(t_rooms *rooms, int *p)
{
	int	i;

	i = 0;
	while (i < rooms->num_of_rooms - 1)
	{
		if (p[i] != INF)
		{
			rooms->table_paths[p[i]][p[i + 1]] = 0;
			rooms->table_paths[p[i + 1]][p[i]] = 0;
		}
		i++;
	}
}

static t_path	*find_path_for_ant(t_rooms *r)
{
	int		min;
	t_path	*p;
	t_path	*result;

	p = r->head_paths;
	min = p->size_path + p->size_ant;
	result = p;
	while (p)
	{
		if (p->size_path + p->size_ant < min)
		{
			min = p->size_path + p->size_ant;
			result = p;
		}
		p = p->next;
	}
	return (result);
}

void			solver(t_rooms *rooms, int ants)
{
	int		i;
	int		*path;

	while ((path = dijkstra(rooms)) != NULL)
	{
		path_add(rooms, path_new(path));
		delete_paths_from_table(rooms, path);
	}
	i = 1;
	if (rooms->head_paths == NULL)
	{
		free(path);
		rooms_del(rooms);
		ft_printf("ERROR\n");
		exit(1);
	}
	while (i <= ants)
	{
		ant_add(find_path_for_ant(rooms),
				ant_new(i, rooms->start));
		i++;
	}
}
