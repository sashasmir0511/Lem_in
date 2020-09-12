#include "lem_in.h"

static t_path	*delete_empty_path(t_path *p)
{
	t_path	*tmp;

	tmp = p->next;
	if (tmp == p)
	{
		path_del(p);
		return (NULL);
	}
	while (tmp->next != p)
		tmp = tmp->next;
	tmp->next = p->next;
    path_del(p);
	return (tmp->next);
}

static int		get_index_next_room(int now_index, t_path *p)
{
	int	i;

	i = 0;
	while (i < p->size_path && p->path[i] != now_index)
		i++;
	return (p->path[i - 1]);
}

void			print_solver(t_rooms *rooms)
{
	int		fl;
	t_path	*p;
	t_ant	*a;

	p = rooms->head_paths;
	while (p->next != NULL)
		p = p->next;
	p->next = rooms->head_paths;
	p = p->next;
	while (p)
	{
		if (p->size_ant != 0)
		{
			a = p->ant_head;
			fl = TRUE;
			while (a != NULL && fl == TRUE)
			{
				if (a->index_room == rooms->end)
				{
					p->ant_head = a->next;
					free(a);
					p->size_ant -= 1;
					a = p->ant_head;
					continue;
				}
				else if (a->index_room == rooms->start)
					fl = FALSE;
				a->index_room = get_index_next_room(a->index_room, p);
				ft_printf("L%d-%s ", a->index, rooms->table_name[a->index_room]);
				a = a->next;
			}
		}
		else
		{
			p = delete_empty_path(p);
			continue;
		}
		if (p->next == rooms->head_paths)
			ft_printf("\n");
		p = p->next;
	}
	rooms->head_paths = NULL;
}
