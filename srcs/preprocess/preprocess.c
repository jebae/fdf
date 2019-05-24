#include "fdf.h"

int		fdf_preprocess(t_fdf *fdf, char *filename)
{
	int			res;
	t_list		*line_lst;

	fdf->fd = open(filename, O_RDONLY);
	if (fdf->fd == -1)
		return (READ_FILE_FAIL);
	res = read_file(fdf->fd, &line_lst, &(fdf->width), &(fdf->height));
	if (res != READ_FILE_SUCCESS)
		return (res);
	#ifdef DEBUG
		printf(KGRN "res : %d\n" KNRM, res);
		printf(KGRN "width : %d height : %d\n" KNRM, fdf->width, fdf->height);
	#endif
	fdf->polygons = make_polygons(line_lst, fdf->width, fdf->height);
	fdf->polygon_count = fdf->width * fdf->height * 2;
	ft_lstdel(&line_lst, &del_lst_content);
	return (PREPROCESS_SUCCESS);
}