#include "lem_in.h"

t_rooms	*rooms_new()
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms*)ft_memalloc(sizeof(t_rooms))))
		return (NULL);
	rooms->num_of_rooms = 0;
	rooms->start = -1;
	rooms->end = -1;
	rooms->room_list = NULL;
	rooms->table_name = NULL;
	rooms->table_paths = NULL;
	rooms->head_paths = NULL;
	return rooms;
}
