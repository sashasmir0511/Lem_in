/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:14:45 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:14:46 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*ant_new(int index, int index_room)
{
	t_ant	*ant;

	if (!(ant = (t_ant*)ft_memalloc(sizeof(t_ant))))
		return (NULL);
	ant->index = index;
	ant->index_room = index_room;
	ant->next = NULL;
	return (ant);
}
