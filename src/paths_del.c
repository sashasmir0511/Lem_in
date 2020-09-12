/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:12:46 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:12:49 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
