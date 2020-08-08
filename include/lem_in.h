#ifndef LEM_IN
# define LEM_IN
# define INF -1
# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/get_next_line.h"
# include <stdio.h>

typedef struct	s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				status;
	struct s_room	*room_list;
}				t_room;

typedef struct	s_rooms
{
	int			num_of_rooms;
	t_room		*room_list; //назвать head_room_list;
	int			**table_paths;
	char		**table_name;
	int			ant_count;
	int			start;
	int			end;
}				t_rooms;



int main();
int foo();
int	parsing();
int		get_ants();
void	error(t_rooms *rooms, char *line);
void	debug(int ants, t_rooms *rooms);
void	free_split(char **split);



/*
**	Work for list room
*/
t_room		*room_new(char *name, int x, int y, int fl);
void		room_add(t_rooms *rooms, t_room *new_room);
void		room_del(t_room *room);
void		room_print(t_room *room);

/*
**	Work or list rooms
*/
t_rooms		*rooms_new();
void		rooms_add(t_rooms **rooms, int *s, int *e);
void		rooms_del(t_rooms *rooms);
void		table_print(t_rooms *rooms);
void		add_links(t_rooms *rooms, char *line, int *s, int *e);

/*
**	For algorithm
*/
int 		algorithm_work(t_rooms *rooms);
int			find_paths(t_rooms *rooms);
void		dijkstra(t_rooms *rooms);

#endif