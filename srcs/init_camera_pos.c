#include "fdf.h"

static float	get_scale_ratio(t_polygon *polygons, int polygon_size, \
t_mat4 *rot_mat)
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
			vertex = mat_mul_vec(rot_mat, &(polygons[i].vertices[j]));
			if (ABS(vertex.arr[0]) > maxs[0])
				maxs[0] = ABS(vertex.arr[0]);
			if (ABS(vertex.arr[1]) > maxs[1])
				maxs[1] = ABS(vertex.arr[1]);
			j++;
		}
		i++;
	}
	return (X_RATIO(maxs[0]) > Y_RATIO(maxs[1]) ?\
		X_RATIO(maxs[0]) : Y_RATIO(maxs[1]));
}

float			default_z(float width, float height)
{
	float	a;
	float	d;

	a = sqrt(pow(width / 2, 2) + pow(height / 2, 2));
	d = a * (1 / cos(M_PI * 0.25));
	return (sqrt(pow(d, 2) - pow(a, 2)));
}

t_vec4			new_camera_pos(t_vec4 *camera, t_vec4 *focus,\
	float scale_ratio)
{
	t_vec4	fo;
	t_vec4	fc;

	fo = scalar_mul_vec(-1, focus);
	fc = vec_plus_vec(camera, &fo);
	fc = scaler_mul_vec(scale_ratio, &fc);
	return (vec_plus_vec(&fc, focus));
}

t_vec4			init_camera_pos(t_polygon *polygons,\
	float width, float height, t_vec4 *focus)
{
	float		scale_ratio;
	t_vec4 		camera;
	t_mat4 		rot_mat;

	camera = (t_vec4){width, 0, default_z(width, height), 1};
	rot_mat = camera_coord_mat(&camera, focus, 0);
	scale_ratio = get_scale_ratio(polygons, (int)(width * height),\
		&rot_mat);
	camera = new_camera_pos(&camera, focus, scale_ratio);
	return (camera);
}
