#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
#include <stdio.h> // remove after
# include "libft.h"
# include "get_next_line.h"

# define gnl get_next_line
# define READ_FILE_SUCCESS 1
# define READ_FILE_FAIL 0
# define READ_FILE_ERROR -1

void	del_lst_content(void *content, size_t content_size);

int		read_file(char *filename, t_list **line_lst);

#endif
