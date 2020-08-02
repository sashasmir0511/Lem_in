#include "lem_in.h"

void	room_add(t_rooms *rooms, t_room *new_room)
{
	if (new_room == NULL)
		return;
	new_room = *(rooms->room_list);
	*(rooms->room_list) = new_room;
}