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
	#endif
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), -1 * DEGREE_1);
	#ifdef DEBUG
		printf(KYEL "focus : %.2f %.2f %.2f\n" KNRM, cam->focus.arr[0], cam->focus.arr[1], cam->focus.arr[2]);
		printf(KYEL "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
	#endif
	event_render(fdf);
}

void	key_left(void *param)
{
	static t_vec4	axis = (t_vec4){{0, 0, 1, 1}};
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	#ifdef DEBUG
		t_camera	*cam = &(fdf->cam);

		printf(KGRN "focus : %.2f %.2f %.2f\n" KNRM, cam->focus.arr[0], cam->focus.arr[1], cam->focus.arr[2]);
		printf(KGRN "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
	#endif
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), DEGREE_1);
	#ifdef DEBUG
		printf(KYEL "focus : %.2f %.2f %.2f\n" KNRM, cam->focus.arr[0], cam->focus.arr[1], cam->focus.arr[2]);
		printf(KYEL "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
	#endif
	event_render(fdf);
}

void	key_up(void *param)
{
	static t_vec4	z_w = (t_vec4){{0, 0, 1, 1}};
	t_vec4			axis;
	t_vec4			po;
	t_vec4			pc;
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	po = scalar_mul_vec(-1, &(fdf->cam.focus));
	pc = vec_plus_vec(&(fdf->cam.pos), &po);
	axis = vec_cross_vec(&pc, &z_w);
	axis = normalize(&axis);
	#ifdef DEBUG
		t_camera	*cam = &(fdf->cam);

		printf(KGRN "focus : %.2f %.2f %.2f\n" KNRM, cam->focus.arr[0], cam->focus.arr[1], cam->focus.arr[2]);
		printf(KGRN "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
		printf(KGRN "axis : %.2f %.2f %.2f\n" KNRM, axis.arr[0], axis.arr[1], axis.arr[2]);
		printf(KGRN "pc : %.2f %.2f %.2f\n" KNRM, pc.arr[0], pc.arr[1], pc.arr[2]);
	#endif
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), DEGREE_1);
	#ifdef DEBUG
		pc = vec_plus_vec(&(fdf->cam.pos), &po);
		printf(KYEL "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
		printf(KYEL "after pc : %.2f %.2f %.2f\n" KNRM, pc.arr[0], pc.arr[1], pc.arr[2]);
	#endif
	event_render(fdf);
}

void	key_down(void *param)
{
	static t_vec4	z_w = (t_vec4){{0, 0, 1, 1}};
	t_vec4			axis;
	t_vec4			po;
	t_vec4			pc;
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	po = scalar_mul_vec(-1, &(fdf->cam.focus));
	pc = vec_plus_vec(&(fdf->cam.pos), &po);
	axis = vec_cross_vec(&pc, &z_w);
	axis = normalize(&axis);
	#ifdef DEBUG
		t_camera	*cam = &(fdf->cam);

		printf(KGRN "focus : %.2f %.2f %.2f\n" KNRM, cam->focus.arr[0], cam->focus.arr[1], cam->focus.arr[2]);
		printf(KGRN "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
		printf(KGRN "axis : %.2f %.2f %.2f\n" KNRM, axis.arr[0], axis.arr[1], axis.arr[2]);
		printf(KGRN "before pc : %.2f %.2f %.2f\n" KNRM, pc.arr[0], pc.arr[1], pc.arr[2]);
	#endif
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), -1 * DEGREE_1);
	#ifdef DEBUG
		pc = vec_plus_vec(&(fdf->cam.pos), &po);
		printf(KYEL "pos : %.2f %.2f %.2f\n" KNRM, cam->pos.arr[0], cam->pos.arr[1], cam->pos.arr[2]);
		printf(KYEL "after pc : %.2f %.2f %.2f\n" KNRM, pc.arr[0], pc.arr[1], pc.arr[2]);
	#endif
	event_render(fdf);
}