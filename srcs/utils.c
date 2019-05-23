#include "fdf.h"

void	del_lst_content(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

char	*to_next_point(char *row)
{
	while (*row != '\0' && !ft_iswhitespace(*row))
		row++;
	while (*row != '\0' && ft_iswhitespace(*row))
		row++;
	return (row);
}

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