#include "lem_in.h"

void		free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	add_new_room(t_rooms *rooms, char *line, int fl)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (split == NULL || split[0] == NULL || split[0][0] == 'L'
	|| split[1] == NULL || split[2] == NULL)
	{
		free_split(split);
		error(rooms, line);
	}
	else
	{
		room_add(rooms,
			room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2]), fl));
		free_split(split);
		if (fl == 1)
			rooms->start = rooms->num_of_rooms;
		else if (fl == -1)
			rooms->end = rooms->num_of_rooms;
		rooms->num_of_rooms++;
	}
	return (rooms->num_of_rooms - 1);
}

void		rooms_add(t_rooms **rooms)
{
	int		fl;
	char	*line;

	fl = 0;
	*rooms = rooms_new();
	while (get_next_line(0, &line) > 0 && line && *line)
	{
		if (ft_strchr(line, '-') != NULL)
		{
			add_links(*rooms, line);
			break ;
		}
		if ((*rooms)->start == -1 && ft_strequ("##start", line))
			fl = 1;
		else if ((*rooms)->end == -1 && ft_strequ("##end", line))
			fl = -1;
		else if (ft_strequ("##end", line) || ft_strequ("##start", line))
			error(*rooms, line);
		else if (line[0] != '#')
		{
			add_new_room(*rooms, line, fl);
			fl = 0;
		}
		free(line);
	}
}
