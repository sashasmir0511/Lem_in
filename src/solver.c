#include "lem_in.h"

static void	delete_paths_from_table(t_rooms *rooms, int *p)
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

void		solver(t_rooms *rooms, int ants)
{
	int	*path;

	while ((path = dijkstra(rooms)) != NULL)
	{
		paths_add(rooms, paths_new(path));
		delete_paths_from_table(rooms, path);
	}
	ants = ants + 0;
}
