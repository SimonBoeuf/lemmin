#include "includes/lemmin.h"

t_rooms		*init_rooms(void)
{
	t_rooms	*rooms;

	rooms = (t_rooms*)malloc(sizeof(t_rooms));
	rooms->start = NULL;
	rooms->end = NULL;
	rooms->rooms = NULL;
	return (rooms);
}

t_rooms		*get_rooms(void)
{
	static t_rooms	*rooms = NULL;

	if (rooms == NULL)
		rooms = init_rooms();
	return (rooms);
}
