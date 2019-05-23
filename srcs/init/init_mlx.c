#include "fdf.h"

void	init_mlx(t_fdf *fdf, char *window_name)
{
	fdf->p_mlx = mlx_init();
	fdf->p_win = mlx_new_window(fdf->p_mlx, WIDTH, HEIGHT, window_name);
	mlx_hook(fdf->p_win, KEYPRESS, KEYPRESSMASK, NULL, NULL);
	mlx_key_hook(fdf->p_win, &event_keypress, fdf);
}
