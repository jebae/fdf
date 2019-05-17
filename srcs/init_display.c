#include "fdf.h"

void		init_display(t_polygon *polygons, float width, float height,\
	int (*mark_pixel)(t_mlx *, t_coord *, int))
{
	t_vec4		focus;
	t_vec4		camera;
	t_mat4		mat;

	focus = (t_vec4){width / 2, height / 2, 0, 1};
	camera = init_camera_pos(polygons, width, height, &focus);
	mat = camera_coord_mat(&camera, &focus, 0);
	/*
		loop per polygon
		-> rotate by mat
		-> move to window center
		-> mark_pixel
	*/
}
