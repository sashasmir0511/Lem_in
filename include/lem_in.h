#ifndef LEM_IN
# define LEM_IN
# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/get_next_line.h"
# include <stdio.h>

typedef	struct	s_room
{
	char	*name;
	int		coord_x;
	int		coord_y;
	int		status;
}				t_room;

int main();
int foo();
int	parsing();

#endif