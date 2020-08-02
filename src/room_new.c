#include "lem_in.h"

t_room	*room_new(char *name, int x, int y)
{
	t_room	*room;

	if (!(room = (t_room*)ft_memalloc(sizeof(t_room))))
		return (NULL);
	room->name = ft_strdup(name);
	room->coord_x = x;
	room->coord_y = y;
	room->status = 0;
	room->room_list = NULL;
	return (room);
}