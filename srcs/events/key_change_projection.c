#include "fdf.h"

/*
 * parallel
*/
void            key_1(void *param)
{
    t_fdf			*fdf;

    fdf = (t_fdf *)param;
    if (&parallel_projection == fdf->marker.projection)
        return ;
    parallel_proj_marker(&(fdf->marker));
    rezoom_camera(&(fdf->cam), fdf->polygons, fdf->polygon_count, fdf->marker.projection);
    event_render(fdf);
}

/*
 * perspective
*/
void            key_2(void *param)
{
    t_fdf			*fdf;

    fdf = (t_fdf *)param;
    if (&perspective_projection == fdf->marker.projection)
        return ;
    perspective_proj_marker(&(fdf->marker));
    rezoom_camera(&(fdf->cam), fdf->polygons, fdf->polygon_count, fdf->marker.projection);
    event_render(fdf);
}

/*
 * iso
*/
void            key_3(void *param)
{
    t_fdf			*fdf;

    fdf = (t_fdf *)param;
    parallel_proj_marker(&(fdf->marker));
    #ifdef DEBUG
        printf(KRED "cam before : %f\n" KNRM, fdf->cam.zoom);
    #endif
    fdf->cam = init_camera(fdf->polygons, fdf->width, fdf->height, fdf->marker.projection);
    #ifdef DEBUG
        printf(KRED "cam after : %f\n" KNRM, fdf->cam.zoom);
    #endif
    event_render(fdf);
}