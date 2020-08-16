#include "lem_in.h"

void	error(t_rooms *rooms, char *line)
{
	free(line);
	rooms_del(rooms);
	ft_printf("ERROR\n");
	exit(1);
}
