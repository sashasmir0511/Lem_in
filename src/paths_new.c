#include "lem_in.h"

//check
static int	len_paths(int *p)
{
	int	i;

	i = 1;
	while (p[i])
		i++;
	return(i);
}

t_paths	*paths_new(int *p)
{
	t_paths	*paths;

	if (!(paths = (t_paths*)ft_memalloc(sizeof(t_paths))))
		return (NULL);
	paths->paths = p;
	paths->size_paths = len_paths(p);
	paths->next = NULL;
	return paths;
}
