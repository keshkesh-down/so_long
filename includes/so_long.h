#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx/mlx.h"
# include <fcntl.h> //open, close, read, write
# include <stdio.h> //printf
# include <stdlib.h> //malloc, free, perror, exit
# include "../utils/get_next_line/get_next_line.h"

# define SCALE 75
# define MENU "./xpm/menu.xpm"
# define STEVE2 "./xpm/steve/steve2.xpm"
# define STEVE1 "./xpm/steve/steve1.xpm"
# define STEVE3 "./xpm/steve/steve3.xpm"
# define STEVE4 "./xpm/steve/steve4.xpm"
# define STEVE5 "./xpm/steve/steve5.xpm"
# define STEVE6 "./xpm/steve/steve6.xpm"
# define STEVE7 "./xpm/steve/steve7.xpm"
# define STEVE8 "./xpm/steve/steve8.xpm"
# define DIAMOND1 "./xpm/diamond/diamond1.xpm"
# define DIAMOND2 "./xpm/diamond/diamond2.xpm"
# define DIAMOND3 "./xpm/diamond/diamond3.xpm"
# define PORTAL1 "./xpm/portal/portal1.xpm"
# define PORTAL2 "./xpm/portal/portal2.xpm"
# define PORTAL3 "./xpm/portal/portal3.xpm"
# define PORTAL4 "./xpm/portal/portal4.xpm"
# define PORTAL5 "./xpm/portal/portal5.xpm"
# define PORTAL6 "./xpm/portal/portal6.xpm"
# define CREEPER1 "./xpm/creeper/creeper1.xpm"
# define CREEPER2 "./xpm/creeper/creeper2.xpm"
# define CREEPER3 "./xpm/creeper/creeper3.xpm"
# define CREEPER4 "./xpm/creeper/creeper4.xpm"
# define TITLE "so_long"
# define WALL "./xpm/magma.xpm"
# define FLOOR "./xpm/floor.xpm"
# define CLOSE_PORTAL "./xpm/exit_close.xpm"
# define FIELD "./xpm/field_for_str.xpm"
# define KEYUP 13
# define KEYDOWN 1
# define KEYRIGHT 2
# define KEYLEFT 0
# define KEYW 126
# define KEYS 125
# define KEYD 124
# define KEYA 123

typedef struct s_exit_coordinates
{
	int	x;
	int	y;
}	t_exit_coordinates;

typedef struct s_info
{
	void				*mlx;
	void				*win;
	void				*img;
	int					width;
	int					height;
	char				**map;
	int					moves;
	int					collectibles;
	int					x;
	int					y;
	t_exit_coordinates	exit_coordinates;
}	t_info;

void	parse_map(char *filename, t_info *info);
void	handler_errors(int number_of_error);
void	handler_errors_of_map(char *string_of_error, t_info *info);
void	check_chars_of_map(t_info *info, int *player, int *exits);
void	check_walls(t_info *info);
void	draw_game(t_info *info);
void	movement(t_info *info, int y, int x);
void	draw_xpm_image(int block_x, int block_y, char *texture, t_info *info);
int		all_animation(t_info *info);
void	steve_animation(t_info	*info);
void	diamond_animation(t_info	*info);
void	portal_animation(t_info	*info);
void	creeper_animation(t_info	*info);
void	find_portal(t_info *info);
void	exit_from_portal(t_info *info);
void	game_over(t_info *info);
int		free_and_exit(t_info *info);
char	*ft_itoa(int	n);
void	draw_menu(t_info	info);
#endif
