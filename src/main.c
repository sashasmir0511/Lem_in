#include "lem_in.h"

int		main()
{
	int		ants;
	t_rooms	*rooms;

<<<<<<< HEAD
//	ft_printf("%d %d", TRUE, FALSE);
	start = -1;
	end = -1;
=======
>>>>>>> origin/sasha
	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms);
	solver(rooms);
	debug(ants, rooms);
	dijkstra(rooms);

	return 0;
}