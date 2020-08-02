#include "lem_in.h"

t_rooms	*rooms_new()
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms*)ft_memalloc(sizeof(t_rooms))))
		return (NULL);
	rooms->num_of_rooms = 0;
	rooms->room_list = NULL;
	return rooms;
}
