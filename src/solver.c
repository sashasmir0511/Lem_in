#include "lem_in.h"

void	solver(t_rooms *rooms)
{
	int	*paths;
	
	while ((paths = dijkstra(rooms)) != NULL)
	{
		ft_printf("1");
		paths_add(rooms, paths_new(paths));
	}
	
}
