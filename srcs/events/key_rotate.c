/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:34:43 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:34:45 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_right(void *param)
{
	static t_vec4	axis = (t_vec4){{0, 0, 1, 1}};
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), -1 * DEGREE_1);
	event_render(fdf);
}

void	key_left(void *param)
{
	static t_vec4	axis = (t_vec4){{0, 0, 1, 1}};
	t_fdf			*fdf;

	fdf = (t_fdf *)param;
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), DEGREE_1);
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
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), DEGREE_1);
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
	rotate_camera(&(fdf->cam), &axis, &(fdf->cam.focus), -1 * DEGREE_1);
	event_render(fdf);
}
