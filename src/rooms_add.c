#include "lem_in.h"

static void	free_split(char **split)
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

static void	add_new_room(t_rooms **rooms, char *line)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (split == NULL || split[0] == NULL || split[0][0] == 'L'
	|| split[1] == NULL || split[2] == NULL)
	{
		free_split(split);
		error(*rooms, line);
	}
	else
	{
		room_add(*rooms,
			room_new(split[0], ft_atoi(split[1]), ft_atoi(split[2])));
		free_split(split);
		(*rooms)->num_of_rooms++;
	}
}

void	rooms_add(t_rooms **rooms)
{
	//int		fl;
	char	*line;

	//fl = 0;
	*rooms = rooms_new();
	while(get_next_line(0, &line) > 0 && line && *line)
	{
		if (ft_strchr(line, '-') != NULL)
		{
			break;
		}
		if (ft_strequ("##start", line))
			//fl = 1;
			break;
		else if (ft_strequ("##end", line))
			//fl = -1;
			break;
		else
			add_new_room(rooms, line);
		free(line);
	}
}
