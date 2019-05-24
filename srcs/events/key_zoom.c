#include "fdf.h"

void		key_i(void *param)
{
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	fdf->cam.zoom += 1;
	event_render(fdf);
}

void		key_o(void *param)
{
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	fdf->cam.zoom -= 1;
	event_render(fdf);
}