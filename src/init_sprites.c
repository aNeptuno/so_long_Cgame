/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:47:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/18 16:52:57 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_sprites_player(t_game_data *game_data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./assets/ship_up.xpm";
	game_data->sprites->player_up = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->player_up == NULL)
	{
		perror("Error\nError loading collectable image.\n");
		exit(EXIT_FAILURE);
	}
}

static void	init_wall(t_game_data *game_data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./assets/wall.xpm";
	game_data->sprites->obstacle = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->obstacle == NULL)
	{
		perror("Error\nError loading obstacle image.\n");
		exit(EXIT_FAILURE);
	}
}

static void	init_objects(t_game_data *game_data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./assets/collectable.xpm";
	game_data->sprites->collectable = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->collectable == NULL)
	{
		perror("Error\nError loading collectable image.\n");
		exit(EXIT_FAILURE);
	}
	relative_path = "./assets/exit.xpm";
	game_data->sprites->exit = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->exit == NULL)
	{
		perror("Error\nError loading exit image.\n");
		exit(EXIT_FAILURE);
	}
}

void	init_sprites(t_game_data *game_data)
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
	game_data->sprites->bg = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->bg == NULL)
	{
		perror("Error\nError loading background image.\n");
		exit(EXIT_FAILURE);
	}
	init_wall(game_data);
	init_objects(game_data);
	init_sprites_player(game_data);
}
