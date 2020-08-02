#include "lem_in.h"

void	rooms_del(t_rooms *rooms)
{
	while (*(rooms->room_list))
	{
		*(rooms->room_list) = (*(rooms->room_list))->room_list;
		room_del(*(rooms->room_list));
	}
	free(rooms);
}