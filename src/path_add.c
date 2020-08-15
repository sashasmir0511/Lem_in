#include "lem_in.h"

void 	path_add(t_rooms *rooms, t_path *p)
{
	if (p == NULL)
		return;
	if (rooms->head_paths == NULL)
	{
		rooms->head_paths = p;
	}
	else
	{
		p->next = rooms->head_paths;
		rooms->head_paths = p;
	}	
}
