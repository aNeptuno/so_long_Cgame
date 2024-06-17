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

static void	put_bg(t_game_data *game_data, t_mlx_data *mlx_data)
{
	int		y;
	int		x;

	y = 0;
	while (y < 600)//game_data->size_y)
	{
		x = 0;
		while (x < 800)//game_data->size_x)
		{
			mlx_put_image_to_window(mlx_data->mlx, mlx_data->window,
				game_data->sprites->bg, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}

void	put_images(t_game_data *game_data, t_mlx_data *mlx_data)
{
	put_bg(game_data, mlx_data);
}

