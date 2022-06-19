#include "../includes/so_long.h"
void	draw_menu(t_info	info)
{
	info.win = mlx_new_window(info.mlx, 1920, 1080, TITLE);
	draw_xpm_image(0, 0, MENU, &info);
	mlx_loop(info.mlx);
}
