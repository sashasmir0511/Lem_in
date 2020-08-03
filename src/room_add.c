#include "lem_in.h"

void	room_add(t_rooms *rooms, t_room *new_room)
{
	if (new_room == NULL)
		return;
	if (rooms->room_list == NULL)
	{
		rooms->room_list = new_room;
	}
	else
	{
		new_room->room_list = rooms->room_list;
		rooms->room_list = new_room;
	}
}