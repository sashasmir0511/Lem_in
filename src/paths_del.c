#include "lem_in.h"

void	paths_del(t_rooms *rooms)
{
	t_path *p;

	while (rooms->head_paths)
	{
		p = rooms->head_paths;
		rooms->head_paths = rooms->head_paths->next;
		path_del(p);
	}
}
