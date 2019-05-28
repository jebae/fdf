/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:35:13 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 14:35:14 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		handle_err(t_list **line_lst, char **line)
{
	ft_lstdel(line_lst, &del_lst_content);
	ft_memdel((void **)line);
	return (READ_FILE_ERROR);
}

static int		check_line(char *line)
{
	int			color;
	int			width;

	width = 0;
	while (*line != '\0')
	{
		line = (*line == '-') ? (line + 1) : line;
		if (!ft_isdigit(*line))
			return (READ_FILE_ERROR);
		while (*line != '\0' && ft_isdigit(*line))
			line++;
		if (*line == ',' && line++)
		{
			color = ft_hexatoi(line);
			if (color < 0 || color > 0xFFFFFF)
				return (READ_FILE_ERROR);
			line += 2;
			while (ft_ishexdigit(*line))
				line++;
		}
		while (*line != '\0' && *line == ' ')
			line++;
		width++;
	}
	return ((width >= 2) ? width : READ_FILE_ERROR);
}

static void		add_line(t_list **line_lst, char **line)
{
	t_list	*node;

	node = ft_lstnew((void *)(*line), ft_strlen(*line) + 1);
	ft_lstadd(line_lst, node);
	ft_memdel((void **)line);
}

static char		*trim_line(char **line)
{
	char	*trim;

	trim = ft_strtrim(*line);
	ft_memdel((void **)line);
	return (trim);
}

int				read_file(int fd, t_list **line_lst, int *width, int *height)
{
	int		res;
	char	*line;

	if ((res = GNL(fd, &line)) == GNL_ERROR)
		return (READ_FILE_ERROR);
	line = trim_line(&line);
	*width = check_line(line);
	if (*width == READ_FILE_ERROR)
		return (handle_err(NULL, &line));
	add_line(line_lst, &line);
	*height = 1;
	while ((res = GNL(fd, &line)) != GNL_READ_COMPLETE)
	{
		line = trim_line(&line);
		if (res == GNL_ERROR || check_line(line) != *width)
			return (handle_err(line_lst, &line));
		add_line(line_lst, &line);
		(*height)++;
	}
	if (*height < 2)
		return (handle_err(line_lst, NULL));
	*width = *width - 1;
	*height = *height - 1;
	return (READ_FILE_SUCCESS);
}
