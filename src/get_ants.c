/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:13:34 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/13 14:08:31 by gdoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_ants(char **map)
{
	char	*line;
	int		num_of_ant;

	num_of_ant = 0;
	while (1)
	{
		if (get_next_line(0, &line) > 0 && line && *line)
		{
			if (*map == NULL)
				*map = ft_strjoin(line, "\n");
			else
				*map = ft_strjoin_free(*map, ft_strjoin(line, "\n"), 3);
			if (line[0] == '#')
			{
				free(line);
				continue;
			}
			else if (ft_strchr(line, ' ') != NULL
				|| (num_of_ant = ft_atoi(line)) <= 0)
				error(NULL, line, *map);
			free(line);
			return (num_of_ant);
		}
	}
	return (0);
}
