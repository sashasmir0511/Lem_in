#include "lem_in.h"

/*
**	Какая то херня надо переписать
*/
int		get_ants()
{
	char	*line;
	int		num_of_ant;

	while (1)
	{
		if (get_next_line(0, &line) > 0 && line && *line)
		{
			if (line[0] == '#')
			{
				free(line);
				continue;
			}
			else if ((num_of_ant = ft_atoi(line)) <= 0 ) //Уточнить в правилах знак
			{
				free(line);
				ft_printf("ERROR\n");
				exit(1);
			}
			else
			{	
				free(line);
				return num_of_ant;
			}
		}
	}
	return 0;
}
