#include "fdf.h"

static float	get_scale_ratio(t_polygon *polygons, int polygon_size,\
		t_mat4 *camera_mat, t_vec4 (*projection)(t_vec4 *vertex))
{
	int			i;
	int			j;
	float		maxs[2];
	t_vec4		vertex;

	maxs[0] = 0;
	maxs[1] = 0;
	i = 0;
	while (i < polygon_size)
	{
		j = 0;
		while (j < polygons[i].v_count)
		{
			vertex = mat_mul_vec(camera_mat, &(polygons[i].vertices[j]));
			vertex = projection(&vertex);
			if (ABS(vertex.arr[0]) > maxs[0])
				maxs[0] = ABS(vertex.arr[0]);
			if (ABS(vertex.arr[1]) > maxs[1])
				maxs[1] = ABS(vertex.arr[1]);
			j++;
		}
		i++;
	}
	printf(KRED "max : (%.2f, %.2f)\n" KNRM, maxs[0], maxs[1]);
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

t_camera		init_camera(t_polygon *polygons, float width, float height,\
		t_marker *marker)
{
	t_camera 	cam;
	t_mat4 		mat;

	cam.zoom = 1;
	cam.focus = (t_vec4){width / 2, height / 2, 0, 1};
	cam.pos = (t_vec4){width, 0, default_z(width, height), 1};
	mat = camera_mat(&cam);
	cam.zoom = get_scale_ratio(polygons, (int)(width * height * 2),\
		&mat, marker->projection);
	printf(KYEL "camera zoom : %.10f\n" KNRM, cam.zoom);
	cam.roll = 0;
	return (cam);
}

t_camera		init_iso_camera(t_polygon *polygons, float width, float height)
{
	t_camera 	cam;
	t_mat4 		mat;

	cam.zoom = 1;
	cam.focus = (t_vec4){width / 2, height / 2, 0, 1};
	cam.pos = (t_vec4){1 + cam.focus.arr[0], 1 + cam.focus.arr[1], 1, 1};
	mat = camera_mat(&cam);
	cam.zoom = get_scale_ratio(polygons, (int)(width * height * 2),\
		&mat, parallel_projection);
	cam.roll = 0;
	return (cam);
}
