/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 14:07:13 by lhaired           #+#    #+#             */
/*   Updated: 2020/09/12 14:07:16 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

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

typedef struct	s_ant
{
	int				index;
	int				index_room;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_path
{
	int				size_path;
	int				*path;
	int				size_ant;
	t_ant			*ant_head;
	struct s_path	*next;
}				t_path;

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
	int				num_of_rooms;
	t_room			*room_list;
	t_path			*head_paths;
	int				**table_paths;
	char			**table_name;
	int				start;
	int				end;
}				t_rooms;

int				main();
int				get_ants();
void			error(t_rooms *rooms, char *line);
void			debug(int ants, t_rooms *rooms);
void			free_split(char **split);
int				*clear(int *d, int *ver);

/*
**	Work with a list room
*/
t_room			*room_new(char *name, int x, int y, int fl);
void			room_add(t_rooms *rooms, t_room *new_room);
void			room_del(t_room *room);
void			room_print(t_room *room);

/*
**	Work with a list rooms
*/
t_rooms			*rooms_new();
void			rooms_add(t_rooms **rooms);
void			rooms_del(t_rooms *rooms);
void			table_print(t_rooms *rooms);
void			add_links(t_rooms *rooms, char *line);

/*
**	Work with a list paths
*/
void			path_add(t_rooms *rooms, t_path *p);
t_path			*path_new(int *p);
void			path_del(t_path *p);
void			paths_del(t_rooms *rooms);
void			print_path(int n, int *a);
void			print_paths(t_rooms *rooms);

/*
**	Work with a list ant
*/
t_ant			*ant_new(int index, int index_room);
void			ant_add(t_path *p, t_ant *a);
void			ants_del(t_path *p);
void			print_ant(t_ant *a);

/*
**	For algorithm
*/
int				*dijkstra(t_rooms *rooms);
void			solver(t_rooms *rooms, int ants);
void			print_solver(t_rooms *rooms);

#endif
