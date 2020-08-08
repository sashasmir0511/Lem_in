//#include "lem_in.h"

int			algorithm work(t_rooms *rooms)
{
	t_rooms	*first_path;
	find_paths(rooms);
	put_ants(rooms);
	return (1);
}

int					find_paths(t_rooms *rooms)
{
	dijkstra(rooms);
	find_shortest_path(rooms);

}


void				dijkstra(t_rooms *rooms)
{
//	V — множество вершин графа
//	E — множество рёбер графа
//	w[ij] — вес (длина) ребра
//	a — вершина, расстояния от которой ищется
//	U — множество посещённых вершин
//	d[u] — по окончании работы алгоритма равно длине кратчайшего пути
//	p[u] — по окончании работы алгоритма содержит кратчайший путь
//	v — вершина, расстояния до которой ищется

	t_rooms count_rooms; //кол-во комнат
	t_rooms **on_off_room; //посещена или нет комната (вес)
	t_rooms start; //вершина, расстояния от которой ищется
	t_rooms end; //вершина, расстояния до которой ищется
	t_rooms used_rooms; //посещенные комнаты
	len_shortest_path; //длине кратчайшего пути
	*shortest_path; //содержит кратчайший путь

#define INf -1
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
		shortest_path[i]=vector[st][i];
		visited[i]=false;
	}
	shortest_path[num_room]=0;

	for (int i=0;i<n;i++)
	{
		int min=INT_MAX;
		for (int j=0;j<n;j++)
		{
			if (!visited[j] && D[j]<min)
			{
				min=D[j];
				index=j;
			}
		}
		u=index;
		visited[u]=true;
		for(int j=0;j<n;j++)
		{
			if (!visited[j] && w[u][j]!=INT_MAX && D[u]!=INT_MAX && (D[u]+w[u][j]<D[j]))
			{
				D[j]=D[u]+w[u][j];
			}
		}
	}
	cout<<"Стоимость пути из начальной вершины до остальных(Алгоритм Дейкстры):\t\n";
	for (int i=0; i<n; i++)
	{
		if (D[i]!=INT_MAX)
			cout<<st<<" -> "<<i<<" = "<<D[i]<<endl;
		else
			cout<<st<<" -> "<<i<<" = "<<"маршрут недоступен"<<endl;
	}
}




}