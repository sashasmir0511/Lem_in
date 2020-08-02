#ifndef LEM_IN
# define LEM_IN
# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/get_next_line.h"
# include <stdio.h>

typedef struct	s_room
{
	char		*name;
	int			coord_x;
	int			coord_y;
	int			status;
	struct s_room	*room_list;
}				t_room;

typedef struct	s_rooms
{
	int			num_of_rooms;
	t_room		**room_list; //назвать head_room_list;
}				t_rooms;



int main();
int foo();
int	parsing();
int		get_ants();
void	error(t_rooms *rooms, char *line);
void	debug(int ants, t_rooms *rooms);

/*
**	Work for list room
*/
t_room		*room_new(char *name, int x, int y);
void		room_add(t_rooms *rooms, t_room *new_room);
void		room_del(t_room *room);
void		room_print(t_room *room);

/*
**	Work or list rooms
*/
t_rooms		*rooms_new();
void		rooms_add(t_rooms **rooms);
void		rooms_del(t_rooms *rooms);

#endif