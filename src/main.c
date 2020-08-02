#include "lem_in.h"

int		main()
{
	int		ants;
	t_rooms	*rooms;

	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms);
	debug(ants, brooms);
	return 0;
}