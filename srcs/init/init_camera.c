/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:34:56 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:34:56 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float		get_length(float a, float b, float c)
{
	return (sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2)));
}

static float		sphere_radius(t_polygon *polygons,\
	float width, float height, size_t polygon_count)
{
	float		radius;
	float		max_radius;
	size_t		i;
	size_t		j;
	float		center[2];

	center[0] = width / 2;
	center[1] = height / 2;
	max_radius = get_length(center[0], center[1], 0);
	i = 0;
	while (i < polygon_count)
	{
		j = 0;
		while (j < polygons[i].v_count)
		{
			radius = get_length(polygons[i].vertices[j].arr[0] - center[0],\
				polygons[i].vertices[j].arr[1] - center[1],\
				polygons[i].vertices[j].arr[2]);
			if (max_radius < radius)
				max_radius = radius;
			j++;
		}
		i++;
	}
	return (max_radius);
}

t_camera			init_camera(t_polygon *polygons, float width, float height,\
		t_vec4 (*projection)(t_vec4 *))
{
	t_camera	cam;
	t_vec4		pc;
	size_t		polygon_count;
	float		radius;

	polygon_count = (size_t)(width * height * 2);
	cam.focus = (t_vec4){{width / 2, height / 2, 0, 1}};
	pc = (t_vec4){{1, -1, 1}};
	pc = normalize(&pc);
	radius = sphere_radius(polygons, width, height, polygon_count);
	pc = scalar_mul_vec(radius, &pc);
	cam.pos = vec_plus_vec(&(cam.focus), &pc);
	cam.zoom = 1;
	rezoom_camera(&cam, polygons, polygon_count, projection);
	cam.roll = 0;
	return (cam);
}
