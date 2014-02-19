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
	struct s_room	*next;
	struct s_room	*pipes;
}					t_room;

typedef struct		s_rooms
{
	t_room			*start;
	t_room			*end;
	t_room			*rooms;
}					t_rooms;

typedef struct		s_pipe
{
	t_room			*r1;
	t_room			*r2;
	struct s_pipe	*next;
}					t_pipe;

/*
** Core
*/
void	lemmin(void);
int		get_next_line(int const fd, char **line);

/*
** Str_check
*/
int		is_comment(char *str);
int		strstart(char *mask, char *str);

/*
** Line_handle
*/
int		handle_line(char *line);
void	handle_comment(char *s);
void	handle_room(char *s, t_rtype type);
void	handle_pipe(char *s);

/*
** Check_str
*/
int		is_comment(char *str);
int		is_room(char *str);
int		is_pipe(char *str);
int		strstart(char *mask, char *str);

/*
** Rooms
*/
t_rooms	*init_rooms(void);
t_rooms	*get_rooms(void);

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
char	*get_room_name(char **line);
int		get_coord(char **line);

#endif