/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:14:56 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:14:58 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		f2(t_rooms *rooms, int *d, int weight, int *ver)
{
	int		i;
	int		j;
	int		end;

	end = rooms->end;
	j = 1;
	while (end != rooms->start)
	{
		i = 0;
		while (i < rooms->num_of_rooms)
		{
			if (rooms->table_paths[i][end] != 0)
				if ((weight - rooms->table_paths[i][end]) == d[i])
				{
					weight = weight - rooms->table_paths[i][end];
					end = i;
					ver[j] = i;
					j++;
				}
			i++;
		}
	}
}

static int		*recovery_path(t_rooms *rooms, int *d)
{
	int *ver;
	int weight;

	weight = d[rooms->end];
	if (!(ver = (int*)ft_memalloc(sizeof(int) * rooms->num_of_rooms))
		|| weight == 10000)
		return (clear(d, ver));
	ver[0] = rooms->end;
	f2(rooms, d, weight, ver);
	free(d);
	return (ver);
}

static int		f(t_rooms *rooms, int *visited,
	int *shortest_path, int *minindex)
{
	int	i;
	int	min;

	i = 0;
	min = 10000;
	*minindex = 10000;
	while (i < rooms->num_of_rooms)
	{
		if (visited[i] == FALSE && shortest_path[i] < min)
		{
			min = shortest_path[i];
			*minindex = i;
		}
		i++;
	}
	return (min);
}

static	int		*shortest(t_rooms *rooms, int *visited, int *shortest_path)
{
	int	minindex;
	int	min;
	int i;

	minindex = 0;
	while (minindex < 10000)
	{
		min = f(rooms, visited, shortest_path, &minindex);
		if (minindex != 10000)
		{
			i = 0;
			while (i < rooms->num_of_rooms)
			{
				if (rooms->table_paths[minindex][i] > 0)
					if (min + rooms->table_paths[minindex][i]
							< shortest_path[i])
						shortest_path[i] = min
							+ rooms->table_paths[minindex][i];
				i++;
			}
			visited[minindex] = TRUE;
		}
	}
	return (shortest_path);
}

int				*dijkstra(t_rooms *rooms)
{
	int *visited;
	int *shortest_path;
	int i;

	if (!(shortest_path = (int*)ft_memalloc(sizeof(int) * rooms->num_of_rooms))
		|| !(visited = (int*)ft_memalloc(sizeof(int) * rooms->num_of_rooms)))
		return (NULL);
	i = 0;
	while (i < rooms->num_of_rooms)
	{
		shortest_path[i] = 10000;
		visited[i] = FALSE;
		i++;
	}
	shortest_path[rooms->start] = 0;
	shortest(rooms, visited, shortest_path);
	free(visited);
	return (recovery_path(rooms, shortest_path));
}
