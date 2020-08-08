#include "lem_in.h"

int		main()
{
	int		ants;
	int		start;
	int		end;
	t_rooms	*rooms;

	start = -1;
	end = -1;
	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms, &start, &end);
	debug(ants, rooms);
	//alghoritm_work(rooms);
	return 0;
}