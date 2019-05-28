/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_marker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:34:58 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:34:59 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_marker(t_marker *marker, void *p_mlx, void *p_win)
{
	marker->p_mlx = p_mlx;
	marker->p_win = p_win;
	parallel_proj_marker(marker);
}
