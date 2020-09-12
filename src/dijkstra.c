#include "lem_in.h"

static int	*recovery_path(t_rooms *rooms, int *d)
{
	int *ver;
	int	i;
	int	j;
	int weight;
	int temp;
	int	end;

	if (!(ver = (int*)ft_memalloc(sizeof(int) * rooms->num_of_rooms)))
	{
		free(d);
		return (NULL);
	}
	ver[0] = rooms->end;
	weight = d[rooms->end];
	if (weight == 10000)
	{
		free(d);
		free(ver);
		return (NULL);
	}
	end = rooms->end;
	j = 1;
	while (end != rooms->start)
	{
		i = 0;
		while (i < rooms->num_of_rooms)
		{
			if (rooms->table_paths[i][end] != 0)
			{
				temp = weight - rooms->table_paths[i][end];
				if (temp == d[i])
				{
					weight = temp;
					end = i;
					ver[j] = i;
					j++;
				}
			}
			i++;
		}
	}
	free(d);
	return (ver);
}

// Дать нормальное имя переменным и разбить на функции

static	int	*shortest(t_rooms *rooms, int *visited, int *shortest_path)
{
	int	minindex;
	int	min;
	int i;
	int	temp;

	minindex = 0;
	while (minindex < 10000)
	{
		minindex = 10000;
		min = 10000;
		i = 0;
		while (i < rooms->num_of_rooms)
		{
			if (visited[i] == FALSE && shortest_path[i] < min)
			{
				min = shortest_path[i];
				minindex = i;
			}
			i++;
		}
		if (minindex != 10000)
		{
			i = 0;
			while (i < rooms->num_of_rooms)
			{
				if (rooms->table_paths[minindex][i] > 0)
				{
					temp = min + rooms->table_paths[minindex][i];
					if (temp < shortest_path[i])
						shortest_path[i] = temp;
				}
				i++;
			}
			visited[minindex] = TRUE;
		}
	}
	return (shortest_path);
}

int			*dijkstra(t_rooms *rooms)
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
