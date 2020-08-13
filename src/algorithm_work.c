#include "lem_in.h"

int		*dijkstra(t_rooms *rooms)
{
	int *visited = NULL;
	int *shortest_path = NULL;
	int index;
	int u;
	int i, j;

	i = 0;

	if (!(shortest_path = (int*)ft_memalloc(sizeof(rooms->num_of_rooms))))
		return (0);
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
		int min=INF;
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
	//ft_printf("Стоимость пути из начальной вершины до остальных(Алгоритм Дейкстры):\t\n");
//	for (int i=0; i<n; i++)
//	{
//		if (shortest_path[i]!=INF)
//			ft_printf(rooms->start, " -> ",i," = ",shortest_path[i]);
//		else
//			ft_printf(rooms->start, " -> ", i, " = ", "маршрут недоступен");
//	}

		return(shortest_path);

}

