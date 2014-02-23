#ifndef LEMMIN_H
# define LEMMIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "../libft/includes/libft.h"

# define BUFF_SIZE 1024

typedef enum		e_rtype {
					COMMON,
					START,
					END
}					t_rtype;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	t_rtype			type;
	int				dist;
	int				busy;
	struct s_room	*next;
	struct s_room	*pipes;
}					t_room;

typedef struct		s_pipe
{
	t_room			*r1;
	t_room			*r2;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_ant
{
	char			*name;
	struct s_ant	*next;
	int				busy;
}					t_ant;

typedef struct		s_path
{
	t_room			*room;
	t_ant			*ant;
	struct s_path	*next;
}					t_path;

typedef struct		s_paths
{
	t_path			*path;
	int				length;
	struct s_paths	*next;
}					t_paths;

typedef struct		s_anthill
{
	t_room			*start;
	t_room			*end;
	t_room			*rooms;
	t_pipe			*pipes;
	t_paths			*paths;
	t_ant			*ant;
	int				ants;
}					t_anthill;

/*
** Core
*/
void	lemmin(void);
void	get_map(void);
void	find_paths(void);
void	resolve(void);
void	display(void);

/*
** Get next line
*/
int		get_next_line(int const fd, char **line);

/*
** Line_handle
*/
int		handle_line(char *line);
void	handle_ants(char *s);
void	handle_comment(char *s);
void	handle_room(char *s, t_rtype type);
void	handle_pipe(char *s);

/*
** Check_str
*/
int		is_comment(char *str);
int		is_ant_number(char *str);
int		is_room(char *str);
int		is_pipe(char *str);
int		strstart(char *mask, char *str);

/*
** Rooms
*/
t_anthill	*init_anthill(void);
t_anthill	*get_anthill(void);
int			finished(void);

/*
** Room
*/
t_room	*new_room(char *name, int x, int y, t_rtype type);
void	add_room(char *name, int x, int y, t_rtype type);
t_room	*find_room(char *name);

/*
** Pipes
*/
t_pipe	*new_pipe(t_room *r1, t_room *r2);
t_pipe	*get_pipes(t_pipe *p);
void	add_pipe(t_room *r1, t_room *r2);

/*
** Map to Room
*/
int		get_ant_number(char *line);
char	*get_room_name_pipe(char **line);
char	*get_room_name(char **line);
int		get_coord(char **line);
void	add_ants(void);

/*
** Paths
*/
t_paths	*new_paths(t_path *p);
void	add_paths(t_path *p);
int		enough_paths(void);
int		no_paths_left(void);
int		get_paths_number(void);

/*
** Path
*/
t_path	*new_path(t_room *r, int dist);
void	add_path(t_path **p, t_room *r, int dist);
void	dijkstra(void);
void	affect_dist(t_room *r, int dist);
t_path	*get_path(void);

/*
** Ant
*/
t_ant	*new_ant(char *name);
void	add_ant(char *name);
void	move_ants(t_paths *p);
int		get_ants_left(void);
t_ant	*get_next_ant(void);

#endif
