#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
#include <stdio.h> // remove after
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "gmath.h"
# include "draw.h"

# define gnl					get_next_line
# define READ_FILE_SUCCESS		1
# define READ_FILE_FAIL			0
# define READ_FILE_ERROR		-1
# define X_RATIO(X)				((WIDTH * 0.5f - PADDING) / X)
# define Y_RATIO(Y)				((HEIGHT * 0.5f - PADDING) / Y)

# define KEYPRESS				2
# define KEYPRESSMASK			(1L << 0)
# define KEY_ESC				53

typedef struct		s_fdf
{
	int				fd;
	void			*p_mlx;
	void			*p_win;
	t_polygon		*polygons;
}					t_fdf;

void			del_lst_content(void *content, size_t content_size);

char			*to_next_point(char *row);

int				read_file(int fd, t_list **line_lst, int *width, int *height);

t_polygon		*make_polygons(t_list *line_lst, int width, int height);

t_camera		init_camera(t_polygon *polygons, float width, float height,\
		t_marker *marker);

void			init_display(t_polygon *polygons, float width, float height,\
		t_marker *marker);

void			iso_display(t_polygon *polygons, float width, float height,\
		t_marker *marker);

t_camera		init_iso_camera(t_polygon *polygons, float width, float height);

#endif
