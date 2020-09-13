/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:13:55 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/13 14:07:35 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*delete_empty_path(t_rooms *rooms, t_path *p)
{
	t_path	*tmp;

	tmp = p->next;
	if (rooms->head_paths == p)
		rooms->head_paths = p->next;
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

/*
** Print:
** 		L17-d L19-b L18-d L20-c
*/

static void		print_step(t_rooms *rooms, t_path *p)
{
	int		fl;
	t_ant	*a;

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

void			print_solver(t_rooms *rooms)
{
	t_path	*p;

	p = rooms->head_paths;
	while (p->next != NULL)
		p = p->next;
	p->next = rooms->head_paths;
	p = p->next;
	while (p)
	{
		if (p->size_ant != 0)
			print_step(rooms, p);
		else
		{
			p = delete_empty_path(rooms, p);
			continue;
		}
		if (p->next == rooms->head_paths && p->next->size_ant != 0)
			ft_printf("\n");
		p = p->next;
	}
	rooms->head_paths = NULL;
}
