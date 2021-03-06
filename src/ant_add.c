/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:13:17 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:13:18 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ant_add(t_path *p, t_ant *a)
{
	t_ant	*tmp;

	if (a == NULL)
		return ;
	if (p->ant_head == NULL)
		p->ant_head = a;
	else
	{
		tmp = p->ant_head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = a;
	}
	p->size_ant += 1;
}
