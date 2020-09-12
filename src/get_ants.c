/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:13:34 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:13:36 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	get_ants(void)
{
	char	*line;
	int		num_of_ant;

	while (1)
	{
		if (get_next_line(0, &line) > 0 && line && *line)
		{
			ft_printf("%s\n", line);
			if (line[0] == '#')
			{
				free(line);
				continue;
			}
			else if (ft_strchr(line, ' ') != NULL
				|| (num_of_ant = ft_atoi(line)) <= 0)
			{
				free(line);
				ft_printf("ERROR\n");
				exit(1);
			}
			free(line);
			return (num_of_ant);
		}
	}
	return (0);
}
