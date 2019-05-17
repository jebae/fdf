#include "fdf.h"

static float	get_scale_ratio(t_polygon *polygons, int polygon_size, \
t_mat4 *camera_mat)
{
	int			i;
	int			j;
	float		ratio;
	float		maxs[2];
	t_vec4		vertex;

	maxs[0] = 0;
	maxs[1] = 0;
	i = 0;
	while (i < polygon_size)
	{
		j = 0;
		while (j < 4)
		{
			vertex = mat_mul_vec(camera_mat, &(polygons[i].vertices[j]));
			if (ABS(vertex.arr[0]) > maxs[0])
				maxs[0] = ABS(vertex.arr[0]);
			if (ABS(vertex.arr[1]) > maxs[1])
				maxs[1] = ABS(vertex.arr[1]);
			j++;
		}
		i++;
	}
	return (X_RATIO(maxs[0]) > Y_RATIO(maxs[1]) ?\
		Y_RATIO(maxs[1]) : X_RATIO(maxs[0]));
}

float			default_z(float width, float height)
{
	float	a;
	float	d;

	a = sqrt(pow(width / 2, 2) + pow(height / 2, 2));
	d = a * (1 / cos(M_PI * 0.25));
	return (sqrt(pow(d, 2) - pow(a, 2)));
}

t_camera		init_camera_pos(t_polygon *polygons, t_vec4 *focus,\
	float width, float height)
{
	t_camera 	cam;
	t_mat4 		mat;

	cam.zoom = 1;
	cam.focus = *focus;
	cam.pos = (t_vec4){width, 0, default_z(width, height), 1};
	mat = camera_mat(&cam);
	cam.zoom = get_scale_ratio(polygons, (int)(width * height),\
		&mat);
	return (cam);
}
