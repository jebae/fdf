/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:34:08 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:34:09 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include "gmath.h"
# include "draw.h"

# define WINDOW_NAME			"fdf"
# define GNL					get_next_line
# define READ_FILE_SUCCESS		1
# define READ_FILE_FAIL			0
# define READ_FILE_ERROR		-1
# define PREPROCESS_SUCCESS		1
# define X_RATIO(X)				((WIDTH * 0.5f - 2 * PADDING) / X)
# define Y_RATIO(Y)				((HEIGHT * 0.5f - 2 * PADDING) / Y)

# define KEYPRESS				2
# define KEYPRESSMASK			(1L << 0)
# define KEY_ESC				53
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_I					34
# define KEY_O					31
# define KEY_1					18
# define KEY_2					19
# define KEY_3					20

# define RED					0xFF0000
# define GREEN					0x00FF00
# define SKYBLUE				0x87CEEB
# define YELLOW					0xFFFF00

typedef struct	s_fdf
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
}				t_fdf;

/*
** utils
*/
void			del_lst_content(void *content, size_t content_size);
char			*to_next_point(char *row);
void			destroy_polygons(t_polygon **polygons, size_t polygon_count);
void			rezoom_camera(t_camera *cam, t_polygon *polygons,\
	size_t polygon_count, t_vec4 (*projection)(t_vec4 *));

/*
** preprocess
*/
int				fdf_preprocess(t_fdf *fdf, char *filename);
int				read_file(int fd, t_list **line_lst, int *width, int *height);
t_polygon		*make_polygons(t_list *line_lst, int width, int height);

/*
** init
*/
void			init_mlx(t_fdf *fdf, char *window_name);
void			init_marker(t_marker *marker, void *p_mlx, void *p_win);
t_camera		init_camera(t_polygon *polygons, float width, float height,\
		t_vec4 (*projection)(t_vec4 *));
t_camera		init_iso_camera(t_polygon *polygons, float width, float height);

/*
** events
*/
int				event_keypress(int keycode, void *param);
void			event_render(t_fdf *fdf);
void			key_esc(void *param);
void			key_right(void *param);
void			key_left(void *param);
void			key_up(void *param);
void			key_down(void *param);
void			key_i(void *param);
void			key_o(void *param);
void			key_1(void *param);
void			key_2(void *param);
void			key_3(void *param);

/*
** board
*/
void			render_board(t_fdf *fdf);
void			render_usage(t_fdf *fdf);
void			render_status(t_fdf *fdf);

#endif
