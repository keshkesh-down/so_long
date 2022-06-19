#include "../includes/so_long.h"

int	ext_of_map(char *argv)
{
	int		i;
	int		j;
	char	*str_ext_of_map;

	j = 0;
	str_ext_of_map = ".ber";
	i = ft_strlen(argv) - 4;
	while (argv[i])
	{
		if (argv[i] != str_ext_of_map[j] || !str_ext_of_map[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	get_count_of_line(char *filepath)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		handler_errors(2);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		++height;
	}
	free(line);
	close (fd);
	return (height);
}

void	read_map(char *filepath, t_info *info)
{
	int		fd;
	int		rd;
	int		height;

	info->height = get_count_of_line(filepath);
	if (info->height == 0)
		handler_errors(5);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		handler_errors(2);
	rd = fd;
	info->map = (char **)malloc(sizeof(char *) * (info->height + 1));
	if (info->map == NULL)
		handler_errors(4);
	height = 0;
	while (height < info->height)
	{
		info->map[height] = get_next_line(fd);
		height++;
	}
	info->map[height] = 0;
	close(fd);
}

void	map_is_rectangle(t_info *info)
{
	int	line;

	line = 0;
	info->width = ft_strlen(info->map[0]) - 1;
	if (info->width <= 2)
		handler_errors(5);
	while (line < info->height)
	{
		if ((int)ft_strlen(info->map[line++]) - 1 != info->width)
			handler_errors_of_map("Map is not a rectangle!!!", info);
	}
}

void	find_portal(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if (info->map[i][j] == 'E')
			{
				info->exit_coordinates.x = j;
				info->exit_coordinates.y = i;
				draw_xpm_image(j * SCALE, i * SCALE, PORTAL1, info);
			}
			++j;
		}
		++i;
	}
}

void	check_chars_of_map(t_info *info, int *player, int *exits)
{
	int	l;
	int	c;

	l = 0;
	*player = 0;
	*exits = 0;
	while (l < info->height)
	{
		c = 0;
		while (c < info->width)
		{
			if (info->map[l][c] == 'P')
				++*player;
			else if (info->map[l][c] == 'E')
				++*exits;
			else if (info->map[l][c] == 'C')
				++info->collectibles;
			else if (info->map[l][c] != '1' && info->map[l][c] != '0'\
			&& info->map[l][c] != 'Q')
				handler_errors_of_map("Map have \"garbage\" simbols!!!", info);
			c++;
		}
		l++;
	}
}

void	check_walls(t_info *info)
{
	int	line;
	int	column;

	line = 0;
	column = 0;
	while (line < info->height)
	{
		if (line == 0 || line == info->height - 1)
		{
			column = 0;
			while (info->map[line][column] != '\n' && info->map[line][column])
			{
				if (info->map[line][column] != '1')
					handler_errors_of_map \
					("The map is not surrounded by walls!!!", info);
				column++;
			}
		}
		else if (info->map[line][0] != '1'\
		|| info->map[line][info->width - 1] != '1')
			handler_errors_of_map("The map is not surrounded by walls!!!", \
			info);
		line++;
	}
}

void	parse_map(char *filepath, t_info *info)
{
	int	player;
	int	exits;

	if (!ext_of_map(filepath))
		handler_errors(3);
	read_map(filepath, info);
	map_is_rectangle(info);
	check_chars_of_map(info, &player, &exits);
	if (player != 1)
		handler_errors_of_map("In MapFile must be only one player!!!", info);
	if (exits == 0)
		handler_errors_of_map("In MapFile no exits!!!", info);
	if (info->collectibles == 0)
		handler_errors_of_map("In MapFile no collectibles items!!!", info);
	check_walls(info);
}
