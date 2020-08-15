#include "lem_in.h"

void	ant_add(t_path *p, t_ant *a)
{
	if (a == NULL)
		return ;
	if (p->ant_head == NULL)
		p->ant_head = a;
	else
	{
		a->next = p->ant_head;
		p->ant_head = a;
	}
	p->size_ant += 1;
}
