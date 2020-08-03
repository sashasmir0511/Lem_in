#include "lem_in.h"

int		main()
{
	int		ants;
	int		start;
	int		end;
	t_rooms	*rooms;

	start = 0;
	end = 0;
	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms, &start, &end);
	debug(ants, rooms);
	return 0;
}