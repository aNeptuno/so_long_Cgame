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

void	put_bg(t_game_data *game_data)
{
	int		y;
	int		x;

	y = 0;
	while (y < game_data->size_y)
	{
		x = 0;
		while (x < game_data->size_x)
		{
			mlx_put_image_to_window(game_data->mlx, game_data->window,
				game_data->sprites->bg, x, y);
			x += PIXELS;
		}
		y += PIXELS;
	}
}

static void put_object_sprite(t_game_data *gd, char c, int i, int j)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
				gd->sprites->player_up, j * PIXELS, i * PIXELS);
	}
	else if (c == '1')
	{
		mlx_put_image_to_window(gd->mlx, gd->window,
				gd->sprites->obstacle, j * PIXELS, i * PIXELS);
	}
	else if (c == 'E')
	{

	}
	else if (c == 'C')
	{
	}

}

void put_map(t_game_data *gd)
{
	int	i;
	int	j;

	i = 0;
	while (i < gd->rows)
	{
		j = 0;
		while (j < gd->cols)
		{
			put_object_sprite(gd, gd->map[i][j], i , j);
			j++;
		}
		i++;
	}
}
