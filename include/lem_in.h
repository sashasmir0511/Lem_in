#ifndef LEM_IN
# define LEM_IN
# include "../ft_printf/include/ft_printf.h"
# include "stdlib.h"

typedef	struct	s_room
{
	char	*name;
	int		coord_x;
	int		coord_y;
	int		status;
	struct s_room	**links;
}				t_room;

#endif