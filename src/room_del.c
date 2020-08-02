#include "lem_in.h"

void	room_del(t_room *room)
{
	free(room->name);
	free(room);
}
