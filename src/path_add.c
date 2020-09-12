/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:12:35 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:12:37 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	path_add(t_rooms *rooms, t_path *p)
{
	if (p == NULL)
		return ;
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
