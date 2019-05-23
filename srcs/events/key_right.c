#include "fdf.h"

void	key_right(void *param)
{
	static t_vec4	axis = (t_vec4){{0, 0, 1, 1}};
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	#ifdef DEBUG
		t_camera	*cam = &(fdf->cam);

		printf(KGRN "focus : %.2f %.2f %.2f\n" KNRM, cam->focus.arr[0], cam->focus.arr[1], cam->focus.arr[2]);
		printf(KGRN "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
		printf(KGRN "zoom : %f\n" KNRM, cam->zoom);
	#endif
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), -1 * DEGREE_1);
	#ifdef DEBUG
		printf(KYEL "focus : %.2f %.2f %.2f\n" KNRM, cam->focus.arr[0], cam->focus.arr[1], cam->focus.arr[2]);
		printf(KYEL "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
		printf(KYEL "zoom : %f\n" KNRM, cam->zoom);
	#endif
	mlx_clear_window(fdf->p_mlx, fdf->p_win);
	render(fdf->polygons, fdf->polygon_count, &(fdf->cam), &(fdf->marker));
}