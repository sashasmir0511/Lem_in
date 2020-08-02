#include "lem_in.h"

void	room_add(t_rooms *rooms, t_room *new_room)
{
	if (new_room == NULL)
		return;
	if (rooms->room_list == NULL)
	{
		rooms->room_list = &new_room;
		room_print(*(rooms->room_list));
		if ((*(rooms->room_list))->room_list == NULL)
			ft_printf("Good\n");
	}
	else
	{
		//room_print(new_room);
		room_print(*(rooms->room_list));
		//new_room->room_list = *(rooms->room_list);
		//*(rooms->room_list) = new_room;
	}
	// //room_print(new_room);
	// //room_print(*(rooms->room_list));
}