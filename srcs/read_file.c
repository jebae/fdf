#include "fdf.h"

int				handle_err(int fd, t_list **line_lst, char **line)
{
	close(fd);
	ft_lstdel(line_lst, &del_lst_content);
	ft_memdel((void **)line);
	return (READ_FILE_ERROR);
}

static int		check_line(char *line)
{
	int		width;
	int		color;

	width = 0;
	while (*line != '\0')
	{
		while (*line != '\0' && *line == ' ')
			line++;
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

int				read_file(char *filename, t_list **line_lst)
{
	int		fd;
	int		res;
	int		w_preset;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (READ_FILE_FAIL);
	if ((res = gnl(fd, &line)) == GNL_ERROR)
		return (READ_FILE_ERROR);
	if ((w_preset = check_line(line)) == READ_FILE_ERROR)
		return (handle_err(fd, NULL, &line));
	add_line(line_lst, &line);
	while ((res = gnl(fd, &line)) != GNL_READ_COMPLETE)
	{
		if (res == GNL_ERROR || check_line(line) != w_preset)
			return (handle_err(fd, line_lst, &line));
		add_line(line_lst, &line);
	}
	ft_lstrev(line_lst);
	close(fd);
	return (READ_FILE_SUCCESS);
}
