/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:35:10 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:35:11 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_preprocess(t_fdf *fdf, char *filename)
{
	int			res;
	t_list		*line_lst;

	fdf->fd = open(filename, O_RDONLY);
	if (fdf->fd == -1)
		return (READ_FILE_FAIL);
	res = read_file(fdf->fd, &line_lst, &(fdf->width), &(fdf->height));
	if (res != READ_FILE_SUCCESS)
		return (res);
	fdf->polygons = make_polygons(line_lst, fdf->width, fdf->height);
	fdf->polygon_count = fdf->width * fdf->height * 2;
	ft_lstdel(&line_lst, &del_lst_content);
	return (PREPROCESS_SUCCESS);
}
