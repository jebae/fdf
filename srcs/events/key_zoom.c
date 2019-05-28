/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:34:48 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:34:48 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
