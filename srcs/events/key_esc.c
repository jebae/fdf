#include "fdf.h"

void	key_esc(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_destroy_window(fdf->p_mlx, fdf->p_win);
	if (fdf->fd != -1)
		close(fdf->fd);
	destroy_polygons(&(fdf->polygons), fdf->polygon_count);
	printf(KGRN "Program exit...\n" KNRM);
	exit(1);
}