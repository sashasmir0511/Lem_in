#include "lem_in.h"

//check
static int	len_paths(int *p)
{
	return (sizeof(*p) / sizeof(int));
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
