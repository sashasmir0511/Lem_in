#include "lem_in.h"

void	path_del(t_path *p)
{
    ants_del(p);
    free(p->path);
    free(p);
}
