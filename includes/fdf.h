#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
#include <stdio.h> // remove after
# include "libft.h"
# include "get_next_line.h"
# include "draw.h"

# define gnl get_next_line
# define READ_FILE_SUCCESS 1
# define READ_FILE_FAIL 0
# define READ_FILE_ERROR -1
# define WIDTH 1000
# define HEIGHT 800
# define PADDING 30
# define X_RATIO(X) (X / (WIDTH * 0.5f - PADDING))
# define Y_RATIO(Y) (Y / (HEIGHT * 0.5f - PADDING))

void			del_lst_content(void *content, size_t content_size);

char			*to_next_point(char *row);

int				read_file(int fd, t_list **line_lst, int *width, int *height);

t_polygon		*make_polygons(t_list *line_lst, int width, int height);

t_vec4			init_camera_pos(t_polygon *polygons,\
	float width, float height, t_vec4 *focus);

#endif
