#include "fdf.h"

size_t			scan_row(char *row, t_polygon *polygons, int y)
{
	int			x;
	size_t		i;

	polygons[0].vertices[0] = (t_vec4){0, y, ft_atoi(row)};
	x = 1.0f;
	i = 1;
	while (*row != '\0')
	{
		polygons[i - 1].vertices[1] = (t_vec4){x, y, ft_atoi(row)};
		polygons[i].vertices[0] = (t_vec4){x, y, ft_atoi(row)};
		x += 1.0f;
		i = (size_t)x;
	}
	return (i);
}

t_polygon		*make_polygons(t_list *line_lst, size_t width)
{
	/* use width to 2 dimensional array */
	int			y;
	size_t		i;
	t_list		*cur;
	t_polygon	*polygons;

	polygons = (t_polygon *)malloc(sizeof(t_polygon) *\
			(width * (ft_lstlen(line_lst) - 1) + 1));
	cur = line_lst;
	i = 0;
	y = 0;
	while (cur != NULL)
	{
		scan_row((char *)(cur->content), polygons, y);
		cur = cur->next;
		y += 1;
	}
	return (polygons);
}
