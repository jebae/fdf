#include "fdf.h"

void	del_lst_content(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}
