#include "lem_in.h"

int		main(void)
{
	int		ants;
	t_rooms	*rooms;

	rooms = NULL;
	ants = get_ants();
	rooms_add(&rooms);
	solver(rooms, ants);
    ft_printf("\n");
	print_solver(rooms);
	rooms_del(rooms);
	return (0);
}
