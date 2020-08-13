#include "lem_in.h"

int		main()
{
	int		ants;
	t_rooms	*rooms;

	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms);
	solver(rooms);
	debug(ants, rooms);

	return 0;
}