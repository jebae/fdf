#include "fdf.h"

static int		handle_err(t_list **line_lst, char **line)
{
	ft_lstdel(line_lst, &del_lst_content);
	ft_memdel((void **)line);
	return (READ_FILE_ERROR);
}

static size_t	check_line(char *line)
{
	int			color;
	size_t		width;

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
			if (color < 0 || color > 255)
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

int				read_file(int fd, t_list **line_lst, size_t *width)
{
	int		res;
	char	*line;
	size_t	height;

	if ((res = gnl(fd, &line)) == GNL_ERROR)
		return (READ_FILE_ERROR);
	line = trim_line(&line);
	if ((*width = check_line(line)) == READ_FILE_ERROR)
		return (handle_err(NULL, &line));
	add_line(line_lst, &line);
	height = 1;
	while ((res = gnl(fd, &line)) != GNL_READ_COMPLETE && height++)
	{
		line = trim_line(&line);
		if (res == GNL_ERROR || check_line(line) != *width)
			return (handle_err(line_lst, &line));
		add_line(line_lst, &line);
	}
	if (height < 2)
		return (handle_err(line_lst, NULL));
	ft_lstrev(line_lst);
	*width = *width - 1;
	return (READ_FILE_SUCCESS);
}
