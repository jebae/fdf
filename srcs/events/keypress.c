#include "fdf.h"

int		event_keypress(int keycode, void *param)
{
	if (keycode == KEY_ESC)
		key_esc(param);
	else if (keycode == KEY_RIGHT)
		key_right(param);
	else if (keycode == KEY_LEFT)
		key_left(param);
	return (0);
}