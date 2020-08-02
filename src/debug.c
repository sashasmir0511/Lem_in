#include "lem_in.h"

void	room_print(t_room *room)
{
	ft_printf("name_room -> %s\n",	room->name);
	ft_printf("x -> %d y -> %d\n", room->coord_x, room->coord_y);
	ft_printf("status -> %d\n",room->status);
}

void	debug(int ants, t_rooms **rooms)
{
	t_room	*tmp;

	tmp = *((*rooms)->room_list);
	ft_printf("ant -> %d\n", ants);
	ft_printf("num_of_room -> %d\n", (*rooms)->num_of_rooms);
	while(tmp)
	{
		room_print(tmp);
		tmp = tmp->room_list;
	}
}