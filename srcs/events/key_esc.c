/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_esc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:34:39 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:34:40 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_esc(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	mlx_destroy_window(fdf->p_mlx, fdf->p_win);
	if (fdf->fd != -1)
		close(fdf->fd);
	destroy_polygons(&(fdf->polygons), fdf->polygon_count);
	ft_putstr("Program exit...\n");
	exit(1);
}
