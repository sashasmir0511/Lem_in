#include "lem_in.h"

void	rooms_del(t_rooms *rooms)
{
	int		i;
	t_room	*tmp;

	if (rooms->head_paths)
		paths_del(rooms);
	while (rooms->room_list)
	{
		tmp = rooms->room_list;
		rooms->room_list = rooms->room_list->room_list;
		room_del(tmp);
	}
	i = 0;
	while (rooms->table_name != NULL && i < rooms->num_of_rooms)
	{
		free(rooms->table_paths[i]);
		free(rooms->table_name[i]);
		i++;
	}
	if (rooms->table_name != NULL)
		free(rooms->table_name[i]);
	free(rooms);
}
