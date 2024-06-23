/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:21:58 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 18:21:58 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void draw_bg(t_game_data *gd)
{
    mlx_put_image_to_window(gd->mlx, gd->window, gd->sprites->bg_resized, 0, HEADER_HEIGHT);
}

static void	put_player(t_game_data *gd, int i, int j)
{
	t_sprites	*player_sprite;

	if (gd->new_move == 'D')
		player_sprite = gd->sprites->player_down;
	if (gd->new_move == 'U')
		player_sprite = gd->sprites->player_up;
	if (gd->new_move == 'L')
		player_sprite = gd->sprites->player_left;
	if (gd->new_move == 'R')
		player_sprite = gd->sprites->player_right;

	mlx_put_image_to_window(gd->mlx, gd->window,
				player_sprite, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);
	gd->player_x = j;
	gd->player_y = i;
}

static void put_object_sprite(t_game_data *gd, char c, int i, int j, int init)
{
	if (c == 'P')
	{
		put_player(gd, i, j);
	}
	else if (c == '1')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
				gd->sprites->obstacle, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
				gd->sprites->exit, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
				gd->sprites->collectable, j * PIXELS, (i * PIXELS) + HEADER_HEIGHT);
		if (init)
			gd->map_items++;
	}
}

static void draw_header(t_game_data *gd)
{
    int title_pos_x;
    int moves_pos_x;
    int collected_pos_x;

	title_pos_x = (gd->size_x / 2) - 25;
    moves_pos_x = gd->size_x - 200;
    collected_pos_x = gd->size_x / 12;
	mlx_put_image_to_window(gd->mlx, gd->window, gd->sprites->header, title_pos_x, 0);
    mlx_string_put(gd->mlx, gd->window, title_pos_x - 100, 45, 0xFFFFFF, "Cybercat Chronicles: The Ancient Floppy Hunt");
    mlx_string_put(gd->mlx, gd->window, moves_pos_x, 30, 0x800080, "Player Moves:");
    mlx_string_put(gd->mlx, gd->window, moves_pos_x + 100, 30, 0x800080, ft_itoa(gd->player_moves));
	mlx_string_put(gd->mlx, gd->window, collected_pos_x, 30, 0x800080, "Collected Floppy:");
    mlx_string_put(gd->mlx, gd->window, collected_pos_x + 120, 30, 0x800080, ft_itoa(gd->player_items));
}


void put_map(t_game_data *gd, int init)
{
	int	i;
	int	j;

	i = 0;
	while (i < gd->rows)
	{
		j = 0;
		while (j < gd->cols)
		{
			put_object_sprite(gd, gd->map[i][j], i , j, init);
			j++;
		}
		i++;
	}
	draw_header(gd);
}
