#include "fdf.h"

static void         render_rot_degree(t_camera *cam, void *p_mlx, void *p_win)
{
    float                   pan;
    float                   tilt;
    float                   proj_norm;
    t_vec4                  pc;
    t_vec4                  po;

    po = scalar_mul_vec(-1, &(cam->focus));
    pc = vec_plus_vec(&(cam->pos), &po);
    proj_norm = sqrt(pow(pc.arr[0], 2) + pow(pc.arr[1], 2));
    pan = acos(-1 * pc.arr[1] / proj_norm) * (1 / DEGREE_1);
    tilt = acos(proj_norm / vec_norm(&pc)) * (1 / DEGREE_1);
    mlx_string_put(p_mlx, p_win, 5, 300, SKYBLUE, "pan");
    mlx_string_put(p_mlx, p_win, 5, 330, SKYBLUE, "tilt");
    mlx_string_put(p_mlx, p_win, 80, 300, RED, ft_itoa((int)round(pan)));
    mlx_string_put(p_mlx, p_win, 80, 330, RED, ft_itoa((int)round(tilt)));
}

static void         render_zoom(float zoom, void *p_mlx, void *p_win)
{
    mlx_string_put(p_mlx, p_win, 5, 360, SKYBLUE, "zoom");
    mlx_string_put(p_mlx, p_win, 80, 360, RED, ft_itoa((int)round(zoom)));
}

void                render_status(t_fdf *fdf)
{
    render_rot_degree(&(fdf->cam), fdf->p_mlx, fdf->p_win);
    render_zoom(fdf->cam.zoom, fdf->p_mlx, fdf->p_win);
}