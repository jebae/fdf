/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:35:02 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:35:03 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_mlx(t_fdf *fdf, char *window_name)
{
	fdf->p_mlx = mlx_init();
	fdf->p_win = mlx_new_window(fdf->p_mlx, WIDTH, HEIGHT, window_name);
	mlx_hook(fdf->p_win, KEYPRESS, KEYPRESSMASK, NULL, NULL);
	mlx_key_hook(fdf->p_win, &event_keypress, fdf);
}
