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
	if (!(rooms->table_paths = (int**)ft_memalloc(sizeof(int*) * rooms->num_of_rooms))
	|| !(rooms->table_name = (char**)ft_memalloc(sizeof(char*) * (rooms->num_of_rooms + 1))))
		return (1);
	while (r)
	{
		if (!(rooms->table_paths[i] = get_path(rooms->num_of_rooms)))
			return (1);
		rooms->table_name[i] = r->name;
		i++;
		r = r->room_list;
	}
	rooms->table_name[i] = NULL;
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

static void		add_link_to_table(t_rooms *rooms, char *line)
{
	char	**split;
	int		first;
	int		second;

	second = 0;
	split = ft_strsplit(line, '-');
	if (!split[0] || !split[1])
		error(rooms, line);
	first = get_index_room(split[0], rooms);
	second = get_index_room(split[1], rooms);
	if (first == -1 || second == -1)
		error(rooms, line);
	rooms->table_paths[first][second] = 1;
	rooms->table_paths[second][first] = 1;
	free_split(split);
	free(line);
}

void			add_links(t_rooms *rooms, char *_line)
{
	char	*line;

	if (rooms->start == -1 || rooms->end == -1)
		error(rooms, _line);
	if (create_table(rooms))
		error(rooms, _line);
	add_link_to_table(rooms, _line);
	while (get_next_line(0, &line) > 0 && line && *line)
		if (line[0] != '#')
			add_link_to_table(rooms, line);
}
