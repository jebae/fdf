#include "fdf.h"

void	event_render(t_fdf *fdf)
{
	mlx_clear_window(fdf->p_mlx, fdf->p_win);
	init_z_buffer((float *)(fdf->marker.z_buf));
	render(fdf->polygons, fdf->polygon_count, &(fdf->cam), &(fdf->marker));
}

int		event_keypress(int keycode, void *param)
{
	printf("key\n");
	if (keycode == KEY_ESC)
		key_esc(param);
	else if (keycode == KEY_RIGHT)
		key_right(param);
	else if (keycode == KEY_LEFT)
		key_left(param);
	else if (keycode == KEY_UP)
		key_up(param);
	else if (keycode == KEY_DOWN)
		key_down(param);
	else if (keycode == KEY_I)
		key_i(param);
	else if (keycode == KEY_O)
		key_o(param);
	return (0);
}