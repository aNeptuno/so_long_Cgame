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
    mlx_put_image_to_window(gd->mlx, gd->window, gd->sprites->bg_resized, 0, 0);
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
				player_sprite, j * PIXELS, i * PIXELS);
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
				gd->sprites->obstacle, j * PIXELS, i * PIXELS);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
				gd->sprites->exit, j * PIXELS, i * PIXELS);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
				gd->sprites->collectable, j * PIXELS, i * PIXELS);
		if (init)
			gd->map_items++;
	}

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
}
