#include "lem_in.h"

void	rooms_del(t_rooms *rooms)
{
	t_room	*tmp;

	tmp = rooms->room_list;
	while (rooms->room_list)
	{
		rooms->room_list = rooms->room_list->room_list;
		room_del(tmp);
	}
	free(rooms);
}