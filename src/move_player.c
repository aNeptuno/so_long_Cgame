/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:21:29 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/23 14:40:11 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_player_sprite(int coord_x, int coord_y, t_game_data *gd)
{
	if (coord_x == 1)
	{
		gd->new_move = 'R';
	}
	if (coord_x == -1)
	{
		gd->new_move = 'L';
	}
	if (coord_y == 1)
	{
		gd->new_move = 'U';
	}
	if (coord_y == -1)
	{
		gd->new_move = 'D';
	}
}

static void	display_stats(t_game_data *gd)
{
	ft_putstr("Collected Floppy:");
	ft_putstr(ft_itoa(gd->player_items));
	ft_putstr(" | Total moves: ");
	ft_putstr(ft_itoa(gd->player_moves));
}

static void	move_exit(t_game_data *gd)
{
	gd->game_ended = 1;
	if (gd->player_items == gd->map_items && gd->player_moves <= gd->min_moves)
	{
		ft_putstr("\033[1;32m");
		ft_putstr("\nYou won! :D\n");
		display_stats(gd);
		ft_putstr("\033[0m\n");
	}
	else
	{
		ft_putstr("\033[1;31m");
		ft_putstr("\nYou lose :(\n");
		display_stats(gd);
		ft_putstr("\033[0m\n");
	}
}

static void	move_player(int coord_x, int coord_y, t_game_data *gd)
{
	char	c;

	c = gd->map[gd->player_y - coord_y][gd->player_x + coord_x];
	if (c != '1')
	{
		gd->map[gd->player_y][gd->player_x] = '0';
		gd->player_y -= coord_y;
		gd->player_x += coord_x;
		gd->map[gd->player_y][gd->player_x] = 'P';
		change_player_sprite(coord_x, coord_y, gd);
		gd->player_moves++;
		if (c == 'C')
			gd->player_items++;
		if (c == 'E')
		{
			move_exit(gd);
		}
		mlx_clear_window(gd->mlx, gd->window);
		draw_bg(gd);
		put_map(gd, 0);
	}
}

int	render_next_frame_loop(t_game_data *gd)
{
	gd->update_counter++;
	if (gd->update_counter >= UPDATE_FREQ && !gd->game_ended)
	{
		gd->update_counter = 0;
		if (gd->move_up)
		{
			move_player(0, 1, gd);
		}
		if (gd->move_down)
		{
			move_player(0, -1, gd);
		}
		if (gd->move_left)
		{
			move_player(-1, 0, gd);
		}
		if (gd->move_right)
		{
			move_player(1, 0, gd);
		}
	}
	return (0);
}
