#include "lem_in.h"

int		main(void)
{
	int		ants;
	t_rooms	*rooms;

	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms);
	solver(rooms, ants);
	// debug(ants, rooms);
	print_solver(rooms);
	rooms_del(rooms);
	return (0);
}
