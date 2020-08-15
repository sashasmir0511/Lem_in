#ifndef LEM_IN
# define LEM_IN

# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/get_next_line.h"
# include <stdio.h>
# define FALSE	0
# define TRUE	!FALSE
# define INF	-1


typedef struct	s_room
{
	char			*name;
	int				coord_x;
	int				coord_y;
	int				status;
	struct s_room	*room_list;
}				t_room;

typedef struct	s_paths
{
	int				size_paths;
	int				*paths;
	struct s_paths	*next;
}				t_paths;

/*
**	t_rooms
**	num_of_rooms	-> number of rooms in the column
**	start			-> starting room
**	end				-> end room
**	table_paths		-> Adjacency matrix
**	table_name		-> list of names rooms
*/
typedef struct	s_rooms
{
	int			num_of_rooms;
	t_room		*room_list; //назвать head_room_list;
	t_paths		*head_paths;
	int			**table_paths;
	char		**table_name;
	int			start;
	int			end;
}				t_rooms;



int 	main();
int 	foo();
int		parsing();
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
**	Work for list rooms
*/
t_rooms		*rooms_new();
void		rooms_add(t_rooms **rooms);
void		rooms_del(t_rooms *rooms);
void		table_print(t_rooms *rooms);
void		add_links(t_rooms *rooms, char *line);

/*
**	Work for list paths
*/
void 		paths_add(t_rooms *rooms, t_paths *p);
t_paths		*paths_new(int *p);
void		paths_del(t_rooms *rooms);
void		print_path(int N, int *a);
void		print_paths(t_rooms *rooms);

/*
**	For algorithm
*/
int			*dijkstra(t_rooms *rooms);
void		solver(t_rooms *rooms, int ants);

#endif