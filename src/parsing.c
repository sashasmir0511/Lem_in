#include "lem_in.h"


/*
**Закинуть в библиотеку
*/

static int	ft_countword(const char *s)
{
	int	result;

	result = 0;
	while (s && *s != '\0')
	{
		if (*s == ' ')
			result += 1;
		s++;
	}
	if (*s == '\0')
		result += 1;
	return result;
}

static int	get_number_ant(void)
{
	char *line;

	if (get_next_line(0, &line) > 0 && line && *line)
		ft_printf("ant: %s\n", line);
	return 0;
}

static int	get_room(void)
{
	char *line;

	while (get_next_line(0, &line) > 0 && line && *line)
	{
		if (ft_strequ(line, "##start"))
		{
			ft_printf("##start##\n");
		}
		else if (ft_strequ(line, "##end"))
		{
			ft_printf("##end##\n");
		}
		else if (*line == '#')
		{
			ft_printf("comment\n");
		}
		else if (ft_countword(line) == 3)
		{
			ft_printf("room: %s\n", line);
		}
		else
			return 0;
	}
	return 0;
}

static int	get_links(void)
{
	char *line;

	while (get_next_line(0, &line) > 0 && line && *line)
	{
		if (*line == '#')
		{
			ft_printf("comment\n");
		}
		else
			ft_printf("links: %s\n", line);
	}
	return 0;
}

int	parsing()
{
	get_number_ant();
	get_room();
	get_links();
	return 0;
}