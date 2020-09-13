/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:15:12 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:15:14 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	len_path(int *p, int start)
{
	int	i;

	i = 1;
	while (p[i] != start)
		i++;
	i++;
	return (i);
}

t_path		*path_new(int *p, int start)
{
	t_path	*path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->path = p;
	path->size_ant = 0;
	path->size_path = len_path(p, start);
	path->next = NULL;
	return (path);
}
