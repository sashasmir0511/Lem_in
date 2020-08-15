#include "lem_in.h"

void	ants_del(t_path *p)
{
	t_ant	*a;

	while (p->ant_head)
	{
		a = p->ant_head;
		p->ant_head = p->ant_head->next;
		free(a);
	}
}