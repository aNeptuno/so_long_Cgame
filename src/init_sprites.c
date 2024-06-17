/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:47:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 19:47:32 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprites(t_game_data *game_data, t_mlx_data *mlx_data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	game_data->sprites = malloc(sizeof(t_sprites));
	if (game_data->sprites == NULL)
	{
		perror("Error\nMalloc failed for game_data.sprites\n");
		exit(EXIT_FAILURE);
	}
	relative_path = "./assets/background.xpm";
	game_data->sprites->bg = mlx_xpm_file_to_image(mlx_data->mlx, relative_path, &img_width, &img_height);
	if (game_data->sprites->bg == NULL)
	{
		perror("Error\nError loading background image.\n");
        exit(EXIT_FAILURE);
	}
}