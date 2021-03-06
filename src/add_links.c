/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:11:52 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:11:55 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		*get_path(int n)
{
	int	*tr;
	int	i;

	if (!(tr = (int *)malloc(sizeof(int) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		tr[i] = 0;
		i++;
	}
	return (tr);
}

static int		create_table(t_rooms *rooms)
{
	int		i;
	t_room	*r;

	i = 0;
	r = rooms->room_list;
	if (!(rooms->table_paths =
		(int**)ft_memalloc(sizeof(int*) * rooms->num_of_rooms))
	|| !(rooms->table_name =
		(char**)ft_memalloc(sizeof(char*) * rooms->num_of_rooms)))
		return (1);
	while (r)
	{
		if (!(rooms->table_paths[i] = get_path(rooms->num_of_rooms)))
			return (1);
		rooms->table_name[i] = ft_strdup(r->name);
		i++;
		r = r->room_list;
	}
	rooms->start = rooms->num_of_rooms - (1 + rooms->start);
	rooms->end = rooms->num_of_rooms - (1 + rooms->end);
	return (0);
}

static int		get_index_room(char *name, t_rooms *rooms)
{
	int		i;

	i = 0;
	while (i < rooms->num_of_rooms)
	{
		if (ft_strequ(rooms->table_name[i], name))
			return (i);
		i++;
	}
	return (-1);
}

static void		add_link_to_table(t_rooms *rooms, char *line, char **map)
{
	char	**split;
	int		first;
	int		second;

	second = 0;
	split = ft_strsplit(line, '-');
	if (!split[0] || !split[1])
		error(rooms, line, *map);
	first = get_index_room(split[0], rooms);
	second = get_index_room(split[1], rooms);
	if (first == -1 || second == -1)
		error(rooms, line, *map);
	rooms->table_paths[first][second] = 1;
	rooms->table_paths[second][first] = 1;
	free_split(split);
}

void			add_links(t_rooms *rooms, char *line_, char **map)
{
	char	*line;

	if (rooms->start == -1 || rooms->end == -1)
		error(rooms, line_, *map);
	if (create_table(rooms))
		error(rooms, line_, *map);
	add_link_to_table(rooms, line_, map);
	free(line_);
	while (get_next_line(0, &line) > 0 && line && *line)
	{
		*map = ft_strjoin_free(*map, ft_strjoin(line, "\n"), 3);
		if (line[0] != '#')
			add_link_to_table(rooms, line, map);
		free(line);
	}
	free(line);
}
