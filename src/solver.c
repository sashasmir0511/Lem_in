#include "lem_in.h"

void	solver(t_rooms *rooms)
{
	int	*paths;
	
	while ((paths = dijkstra(rooms)) != NULL)
		paths_add(rooms, paths_new(paths));
	
}
