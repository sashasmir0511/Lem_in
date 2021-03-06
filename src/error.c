/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:12:25 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/13 14:06:36 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		*clear(int *d, int *ver)
{
	if (d != NULL)
		free(d);
	if (ver != NULL)
		free(ver);
	return (NULL);
}

void	error(t_rooms *rooms, char *line, char *map)
{
	if (line != NULL)
		free(line);
	if (map != NULL)
		free(map);
	if (rooms != NULL)
		rooms_del(rooms);
	ft_printf("ERROR\n");
	exit(1);
}
