#include "fdf.h"

void			init_display(t_polygon *polygons, float width, float height,\
		t_marker *marker)
{
	t_vec4		focus;
	t_camera	cam;
	t_mat4		mat;

	focus = (t_vec4){width / 2, height / 2, 0, 1};
	cam = init_camera_pos(polygons, &focus, width, height);
	cam.roll = 0;
	mat = camera_mat(&cam);
	display(polygons, (int)(width * height), &mat, marker);
}
