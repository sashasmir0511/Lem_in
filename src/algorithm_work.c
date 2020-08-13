#include "lem_in.h"

int		*dijkstra(t_rooms *rooms)
{
	int *visited = NULL;
	int *shortest_path = NULL;
	int index;
	int u;
	int i;
	int j;

	i = 0;
	if (!(shortest_path = (int*)ft_memalloc(sizeof(rooms->num_of_rooms)))
		|| !(visited = (int*)ft_memalloc(sizeof(rooms->num_of_rooms))))
		return (NULL);
	while (i < rooms->num_of_rooms)
	{
		shortest_path[i] = rooms->table_paths[rooms->start][i];
		visited[i] = FALSE;
		i++;
	}
	shortest_path[rooms->start]=0;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		int min = INF;
		for (int j=0;j < rooms->num_of_rooms; j++)
		{
			if (!visited[j] && shortest_path[j] < min)
			{
				min = shortest_path[j];
				index=j;
			}
		}
		u=index;
		visited[u] = TRUE;
		j = 0;
		while (j < rooms->num_of_rooms)
		{
			if (!visited[j] && rooms->table_paths[u][j] != INF && shortest_path[u] != INF && (shortest_path[u]+ rooms->table_paths[u][j] < shortest_path[j]))
			{
				shortest_path[j] = shortest_path[u] + rooms->table_paths[u][j];
			}
			j++;
		}
		i++;
	}
	return(shortest_path);
}

