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

	int begin_index = 0;
	visited[0] = rooms->end + 1; // начальный элемент - конечная вершина
	int k = 1; // индекс предыдущей вершины
	int weight = shortest_path[rooms->end]; // вес конечной вершины
	int num = 0;
	int temp = 0;

	while (rooms->end !=  begin_index) // пока не дошли до начальной вершины
	{
		ft_printf("dikstra1");
		while (num < rooms->num_of_rooms) // просматриваем все вершины
		{
			ft_printf("%i", "num room", rooms->num_of_rooms, "\n");
			if (rooms->table_paths[num][rooms->end] != 0)   // если связь есть
			{

				 temp = weight - rooms->table_paths[num][rooms->end]; // определяем вес пути из предыдущей вершины
				if (temp == shortest_path[num]) // если вес совпал с рассчитанным
				{                 // значит из этой вершины и был переход
					weight = temp; // сохраняем новый вес
					rooms->end = num;       // сохраняем предыдущую вершину
					visited[k] = num + 1; // и записываем ее в массив
					k++;
				}
			}
			num++;

		}
		rooms->end -= num;

	}
//	// Вывод пути (начальная вершина оказалась в конце массива из k элементов)
	ft_printf("\nВывод кратчайшего пути\n");
	for (int i = k - 1; i >= 0; i--) {
		ft_printf("%3d ", shortest_path[i]);
	}

	return (shortest_path);


	//getchar(); getchar();
}

