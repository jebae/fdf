#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
#include <stdio.h> // remove after
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "gmath.h"
# include "draw.h"

# define WINDOW_NAME			"fdf"
# define gnl					get_next_line
# define READ_FILE_SUCCESS		1
# define READ_FILE_FAIL			0
# define READ_FILE_ERROR		-1
# define PREPROCESS_SUCCESS		1
# define X_RATIO(X)				((WIDTH * 0.5f - PADDING) / X)
# define Y_RATIO(Y)				((HEIGHT * 0.5f - PADDING) / Y)

# define KEYPRESS				2
# define KEYPRESSMASK			(1L << 0)
# define KEY_ESC				53
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124

typedef struct		s_fdf
{
	int				fd;
	int				width;
	int				height;
	void			*p_mlx;
	void			*p_win;
	t_polygon		*polygons;
	size_t			polygon_count;
	t_camera		cam;
	t_marker		marker;
}					t_fdf;

/*
 * utils
*/
void			del_lst_content(void *content, size_t content_size);
char			*to_next_point(char *row);
void			destroy_polygons(t_polygon **polygons, size_t polygon_count);

/*
 * preprocess
*/
int				fdf_preprocess(t_fdf *fdf, char *filename, int *width, int *height);
int				read_file(int fd, t_list **line_lst, int *width, int *height);
t_polygon		*make_polygons(t_list *line_lst, int width, int height);

/*
 * init
*/
void			init_mlx(t_fdf *fdf, char *window_name);
void			init_marker(t_marker *marker, void *p_mlx, void *p_win);
t_camera		init_camera(t_polygon *polygons, float width, float height,\
		t_vec4 (*projection)(t_vec4 *));
t_camera		init_iso_camera(t_polygon *polygons, float width, float height);

/*
 * events
*/
int				event_keypress(int keycode, void *param);
void			key_esc(void *param);
void			key_right(void *param);

#endif
