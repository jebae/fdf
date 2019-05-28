/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_polygons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:35:07 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:35:07 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			handle_upper_polygon(t_polygon *upper, t_vec4 v,\
		int is_most_left, int is_most_right)
{
	if (!is_most_left)
		(upper - 1)->vertices[1] = v;
	if (!is_most_right)
	{
		upper->vertices[2] = v;
		(upper + 1)->vertices[2] = v;
	}
}

static void			handle_lower_polygon(t_polygon *lower, t_vec4 v,\
		int is_most_left, int is_most_right)
{
	if (!is_most_left)
	{
		(lower - 2)->vertices[1] = v;
		(lower - 1)->vertices[0] = v;
	}
	if (!is_most_right)
		lower->vertices[0] = v;
}

static void			read_row(char *row, t_polygon *upper, t_polygon *lower,\
		int width)
{
	static int	y = 0;
	int			x;
	t_vec4		v;

	x = 0;
	while (*row != '\0')
	{
		v = (t_vec4){{(float)x, (float)y, (float)ft_atoi(row), 1.0f}};
		if (upper != NULL)
			handle_upper_polygon(&(upper[2 * x]), v, x == 0, x == width);
		if (lower != NULL)
			handle_lower_polygon(&(lower[2 * x]), v, x == 0, x == width);
		row = to_next_point(row);
		x++;
	}
	y++;
}

static t_polygon	*init_polygons(int width, int height)
{
	t_polygon	*polygons;
	int			size;

	size = width * height * 2;
	polygons = ft_memalloc(sizeof(t_polygon) * size);
	while (--size >= 0)
		polygons[size] = new_polygon(3, 0xFFFFFF, 0x000000);
	return (polygons);
}

t_polygon			*make_polygons(t_list *line_lst, int width, int height)
{
	t_list		*cur;
	t_polygon	*polygons;
	t_polygon	*upper;
	t_polygon	*lower;

	polygons = init_polygons(width, height);
	upper = NULL;
	lower = polygons;
	cur = line_lst;
	while (height >= 0)
	{
		read_row((char *)(cur->content), upper, lower, width);
		upper = lower;
		height--;
		lower = (height == 0) ? NULL : lower + (width * 2);
		cur = cur->next;
	}
	return (polygons);
}
