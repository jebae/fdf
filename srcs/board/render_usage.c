#include "fdf.h"

void         render_usage(t_fdf *fdf)
{
    void        *p_mlx;
    void        *p_win;

    p_mlx = fdf->p_mlx;
    p_win = fdf->p_win;
    mlx_string_put(p_mlx, p_win, 5, 5, YELLOW, "[UP]");
    mlx_string_put(p_mlx, p_win, 5, 35, YELLOW, "[DOWN]");
    mlx_string_put(p_mlx, p_win, 5, 65, YELLOW, "[RIGHT]");
    mlx_string_put(p_mlx, p_win, 5, 95, YELLOW, "[LEFT]");
    mlx_string_put(p_mlx, p_win, 5, 125, YELLOW, "[I]");
    mlx_string_put(p_mlx, p_win, 5, 155, YELLOW, "[O]");
    mlx_string_put(p_mlx, p_win, 5, 185, YELLOW, "[1]");
    mlx_string_put(p_mlx, p_win, 5, 215, YELLOW, "[2]");
    mlx_string_put(p_mlx, p_win, 5, 245, YELLOW, "[3]");
    mlx_string_put(p_mlx, p_win, 80, 5, GREEN, "rotate up");
    mlx_string_put(p_mlx, p_win, 80, 35, GREEN, "rotate down");
    mlx_string_put(p_mlx, p_win, 80, 65, GREEN, "rotate right");
    mlx_string_put(p_mlx, p_win, 80, 95, GREEN, "rotate left");
    mlx_string_put(p_mlx, p_win, 80, 125, GREEN, "zoom in");
    mlx_string_put(p_mlx, p_win, 80, 155, GREEN, "zoom out");
    mlx_string_put(p_mlx, p_win, 80, 185, GREEN, "parallel");
    mlx_string_put(p_mlx, p_win, 80, 215, GREEN, "perspective");
    mlx_string_put(p_mlx, p_win, 80, 245, GREEN, "iso");
}