/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:35:26 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:35:26 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **args)
{
	t_fdf		fdf;

	if (argc != 2)
		return (0);
	if (fdf_preprocess(&fdf, args[1]) != PREPROCESS_SUCCESS)
	{
		ft_putstr("Preprocess fail\n");
		return (0);
	}
	init_mlx(&fdf, WINDOW_NAME);
	init_marker(&(fdf.marker), fdf.p_mlx, fdf.p_win);
	fdf.cam = init_camera(fdf.polygons, fdf.width, fdf.height,\
		fdf.marker.projection);
	render(fdf.polygons, fdf.polygon_count, &(fdf.cam), &(fdf.marker));
	render_board(&fdf);
	mlx_loop(fdf.p_mlx);
	return (0);
}
