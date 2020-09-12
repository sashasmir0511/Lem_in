/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:12:25 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:12:26 by lhaired          ###   ########.fr       */
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

void	error(t_rooms *rooms, char *line)
{
	free(line);
	rooms_del(rooms);
	ft_printf("ERROR\n");
	exit(1);
}
