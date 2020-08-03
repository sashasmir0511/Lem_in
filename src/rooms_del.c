#include "lem_in.h"

void	rooms_del(t_rooms *rooms)
{
	int		i;
	t_room	*tmp;

	tmp = rooms->room_list;
	while (rooms->room_list)
	{
		rooms->room_list = rooms->room_list->room_list;
		room_del(tmp);
	}
	i = 0;
	while (i < rooms->num_of_rooms)
	{
		free(rooms->table_paths[i]);
		free(rooms->table_name[i]);
		i++;
	}
	free(rooms->table_name[i]);
	free(rooms);
}
