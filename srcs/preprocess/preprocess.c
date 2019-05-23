#include "fdf.h"

int		fdf_preprocess(t_fdf *fdf, char *filename, int *width, int *height)
{
	int			res;
	t_list		*line_lst;

	fdf->fd = open(filename, O_RDONLY);
	if (fdf->fd == -1)
		return (READ_FILE_FAIL);
	res = read_file(fdf->fd, &line_lst, width, height);
	if (res != READ_FILE_SUCCESS)
		return (res);
	#ifdef DEBUG
		printf(KGRN "res : %d\n" KNRM, res);
		printf(KGRN "width : %d height : %d\n" KNRM, *width, *height);
	#endif
	fdf->polygons = make_polygons(line_lst, *width, *height);
	fdf->polygon_count = (*width) * (*height) * 2;
	ft_lstdel(&line_lst, &del_lst_content);
	return (PREPROCESS_SUCCESS);
}