#include "lem_in.h"

void	print_paths(t_rooms *rooms, int *a)
{
	int i;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		ft_printf("%d ", a[i]);
		i++;
	}
	ft_printf("\n");
}

int		main()
{
	int		ants;
	t_rooms	*rooms;

	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms);
	debug(ants, rooms);
	//solver(rooms);
	print_paths(rooms, dijkstra(rooms));
	return 0;
}
