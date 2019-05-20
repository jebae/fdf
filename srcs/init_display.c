#include "fdf.h"

void			init_display(t_polygon *polygons, float width, float height,\
		t_marker *marker)
{
	t_vec4		focus;
	t_camera	cam;
	t_mat4		mat;

	cam = init_camera(polygons, width, height, marker);
	mat = camera_mat(&cam);
	display(polygons, (int)(width * height), &mat, marker);
}

void			iso_display(t_polygon *polygons, float width, float height,\
		t_marker *marker)
{
	t_vec4		focus;
	t_camera	cam;
	t_mat4		mat;

	cam = init_iso_camera(polygons, width, height);
	mat = camera_mat(&cam);
	display(polygons, (int)(width * height), &mat, marker);
}
