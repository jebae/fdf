/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:35:23 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:35:23 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_lst_content(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

char	*to_next_point(char *row)
{
	while (*row != '\0' && !ft_iswhitespace(*row))
		row++;
	while (*row != '\0' && ft_iswhitespace(*row))
		row++;
	return (row);
}
