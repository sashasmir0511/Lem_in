#include "lem_in.h"

//check

static int	len_path(int *p)
{
	int	i;

	i = 1;
	while (p[i])
		i++;
	return (i);
}

t_path		*path_new(int *p)
{
	t_path	*path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (NULL);
	path->path = p;
	path->size_ant = 0;
	path->size_path = len_path(p);
	path->next = NULL;
	return (path);
}
