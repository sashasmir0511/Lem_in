#include "lem_in.h"

int			algorithm_work(t_rooms *rooms)
{
	t_rooms	*first_path;
	find_paths(rooms);
	put_ants(rooms);
	return(0);
}

int					find_paths(t_rooms *rooms)
{
	dijkstra(rooms);
	find_shortest_path(rooms);

}


void				dijkstra(t_rooms *rooms)
{
//	t_rooms count_rooms; //кол-во комнат
//	t_rooms **on_off_room; //посещена или нет комната (вес)
//	t_rooms start; //вершина, расстояния от которой ищется
//	t_rooms end; //вершина, расстояния до которой ищется
//	t_rooms used_rooms; //посещенные комнаты
//	len_shortest_path; //длине кратчайшего пути
//	*shortest_path; //содержит кратчайший путь

	int **vector; //матрица путей
	bool *visited;
	int num_room;
	int **shortest_path;
	int index;
	int u;
	// тут нужно задать размер vector в зависимости от числа комнат
//	w.resize(n);
//	for (int i=0;i<n;i++)
//		w[i].resize(n);


	for(int i=0;i<n;i++)
	{
		shortest_path[i]=vector[num_room][i];
		visited[i]=false;
	}
	shortest_path[num_room]=0;

	for (int i=0;i<n;i++)
	{
		int min=INF;
		for (int j=0;j<n;j++)
		{
			if (!visited[j] && shortest_path[j] < min)
			{
				min=shortest_path[j];
				index=j;
			}
		}
		u=index;
		visited[u]=true;
		for(int j=0;j<n;j++)
		{
			if (!visited[j] && vector[u][j]!=INF && shortest_path[u] != INF && (shortest_path[u]+vector[u][j] < shortest_path[j]))
			{
				shortest_path[j] = shortest_path[u]+vector[u][j];
			}
		}
	}
	//cout<<"Стоимость пути из начальной вершины до остальных(Алгоритм Дейкстры):\t\n";
//	for (int i=0; i<n; i++)
//	{
//		if (D[i]!=INT_MAX)
//			cout<<st<<" -> "<<i<<" = "<<D[i]<<endl;
//		else
//			cout<<st<<" -> "<<i<<" = "<<"маршрут недоступен"<<endl;
//	}
//}




}