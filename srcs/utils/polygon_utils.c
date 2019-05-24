#include "fdf.h"

void	destroy_polygons(t_polygon **polygons, size_t polygon_count)
{
	size_t		i;
	t_polygon	*p;

	if (polygons == NULL || polygon_count == 0)
		return ;
	p = *polygons;
	i = 0;
	while (i < polygon_count)
	{
		ft_memdel((void **)&(p[i].vertices));
		i++;
	}
	ft_memdel((void **)polygons);
}