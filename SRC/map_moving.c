
#include "so_long.h"

static void	try_move(t_game *g, int new_x, int new_y)
{
	char	target;

	if (new_x < 0 || new_x >= g->map.col || new_y < 0 || new_y >= g->map.row)
		return ;
	target = g->map.grid[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'C')
	{
		g->player.collected++;
		g->map.grid[new_y][new_x] = '0';
	}
	if (target == 'E')
	{
		if (g->player.collected == g->map.total_collectibles)
			ft_cleanup_and_exit(g);
		return ;
	}
	g->player.x = new_x;
	g->player.y = new_y;
	g->player.moves++;
	ft_draw_map(g);
}

int	ft_handle_keypress(int keycode, t_game *g)
{
	int	new_x;
	int	new_y;

	new_x = g->player.x;
	new_y = g->player.y;
	if (keycode == 65307)
		return (ft_cleanup_and_exit(g));
	else if (keycode == 'w' || keycode == 'W' || keycode == 65362)
		new_y--;
	else if (keycode == 's' || keycode == 'S' || keycode == 65364)
		new_y++;
	else if (keycode == 'a' || keycode == 'A' || keycode == 65361)
		new_x--;
	else if (keycode == 'd' || keycode == 'D' || keycode == 65363)
		new_x++;
	else
		return (0);
	try_move(g, new_x, new_y);
	return (0);
}
