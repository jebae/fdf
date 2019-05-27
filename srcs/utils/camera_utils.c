#include "fdf.h"

static float	    get_scale_ratio(t_polygon *polygons, size_t polygon_count,\
		t_mat4 *camera_mat, t_vec4 (*projection)(t_vec4 *vertex))
{
	size_t		i;
	size_t		j;
	float		maxs[2];
	t_vec4		vertex;

	maxs[0] = 0;
	maxs[1] = 0;
	i = 0;
	while (i < polygon_count)
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
	return (X_RATIO(maxs[0]) > Y_RATIO(maxs[1]) ?\
		Y_RATIO(maxs[1]) : X_RATIO(maxs[0]));
}

void			    rezoom_camera(t_camera *cam, t_polygon *polygons, size_t polygon_count,\
    t_vec4 (*projection)(t_vec4 *))
{
    t_mat4      mat;
    float       scale;

    mat = camera_mat(cam);
    scale = get_scale_ratio(polygons, polygon_count, &mat, projection);
	cam->zoom *= scale;
}