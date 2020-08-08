#include "lem_in.h"

void	room_print(t_room *room)
{
	if (room == NULL)
		return;
	ft_printf("name_room -> %s\n",	room->name);
	ft_printf("x -> %d y -> %d\n", room->coord_x, room->coord_y);
	ft_printf("status -> %d\n", room->status);
}

void	table_print(t_rooms *rooms)
{
	int	i;
	int j;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		j = 0;
		ft_printf("%s", rooms->table_name[i]);
		while (j < rooms->num_of_rooms)
		{
			ft_printf(" %d", rooms->table_paths[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	debug(int ants, t_rooms *rooms)
{
	t_room	*tmp;

	if (rooms->room_list != NULL)
		tmp = rooms->room_list;
	else
		tmp = NULL;
	ft_printf("\nant -> %d\n", ants);
	ft_printf("num_of_room -> %d\n", rooms->num_of_rooms);
	ft_printf("start -> %s(%d)\tend -> %s(%d)\n",
		rooms->table_name[rooms->start], rooms->start,
		rooms->table_name[rooms->end], rooms->end);
	ft_printf("----------------\n");
	// while(tmp)
	// {
	// 	room_print(tmp);
	// 	tmp = tmp->room_list;
	// 	ft_printf("\n");
	// }
	table_print(rooms);
}