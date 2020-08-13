#include "lem_in.h"

int		*dijkstra(t_rooms *rooms)
{
	int *visited = NULL;
	int *shortest_path = NULL;
	int index;
	int u;
	int i;
	int j;

	if (!(shortest_path = (int *) ft_memalloc(sizeof(rooms->num_of_rooms)))
		|| !(visited = (int *) ft_memalloc(sizeof(rooms->num_of_rooms))))
		return (NULL);
	i = 0;
	while (i < rooms->num_of_rooms) {
		shortest_path[i] = rooms->table_paths[rooms->start][i];
		visited[i] = FALSE;
		i++;
	}
	shortest_path[rooms->start] = 0;

	i = 0;
	while (i < rooms->num_of_rooms) {
		int min = INF;
		for (int j = 0; j < rooms->num_of_rooms; j++) {
			if (!visited[j] && (shortest_path[j] < min || min == INF)) {
				min = shortest_path[j];
				index = j;
			}
		}
		u = index;
		visited[u] = TRUE;
		j = 0;
		while (j < rooms->num_of_rooms) {
			if (!visited[j] && rooms->table_paths[u][j] != INF
				&& shortest_path[u] != INF
				&& (shortest_path[u] + rooms->table_paths[u][j] < shortest_path[j])) {
				shortest_path[j] = shortest_path[u] + rooms->table_paths[u][j];
			}
			j++;
		}
		i++;
	}


	//int ver[SIZE]; // массив посещенных вершин
	//int end = 3; // индекс конечной вершины = 5 - 1

	visited[0] = rooms->end + 1; // начальный элемент - конечная вершина
	int k = 1; // индекс предыдущей вершины
	int weight = shortest_path[rooms->end]; // вес конечной вершины

	while (rooms->end != rooms->num_of_rooms) // пока не дошли до начальной вершины
	{
		for (int i = 0; i < rooms->num_of_rooms; i++) // просматриваем все вершины
			if (rooms->table_paths[i][rooms->end] != 0)   // если связь есть
			{
				int temp = weight - rooms->table_paths[i][rooms->end]; // определяем вес пути из предыдущей вершины
				if (temp == shortest_path[i]) // если вес совпал с рассчитанным
				{                 // значит из этой вершины и был переход
					weight = temp; // сохраняем новый вес
					rooms->end = i;       // сохраняем предыдущую вершину
					visited[k] = i + 1; // и записываем ее в массив
					k++;
				}
			}
	}
	// Вывод пути (начальная вершина оказалась в конце массива из k элементов)
	ft_printf("\nВывод кратчайшего пути\n");
	for (int i = k - 1; i >= 0; i--)
		ft_printf("%3d ",visited[i]);

	return (shortest_path);


	//getchar(); getchar();
}

