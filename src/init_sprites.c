/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:47:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/02 17:11:39 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_sprites_player_help(t_game_data *game_data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./assets/cat_left.xpm";
	game_data->sprites->player_left = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->player_left == NULL)
	{
		perror("Error\nError loading player image.\n");
		exit(EXIT_FAILURE);
	}
	relative_path = "./assets/cat_right.xpm";
	game_data->sprites->player_right = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->player_right == NULL)
	{
		perror("Error\nError loading player image.\n");
		exit(EXIT_FAILURE);
	}
}

static void	init_sprites_player(t_game_data *game_data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./assets/cat_up.xpm";
	game_data->sprites->player_up = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->player_up == NULL)
	{
		perror("Error\nError loading player image.\n");
		exit(EXIT_FAILURE);
	}
	relative_path = "./assets/cat_down.xpm";
	game_data->sprites->player_down = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->player_down == NULL)
	{
		perror("Error\nError loading player image.\n");
		exit(EXIT_FAILURE);
	}
	init_sprites_player_help(game_data);
}

static void	init_walls_and_header(t_game_data *game_data)
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
	relative_path = "./assets/title.xpm";
	game_data->sprites->header = mlx_xpm_file_to_image(game_data->mlx,
			relative_path, &img_width, &img_height);
	if (game_data->sprites->header == NULL)
	{
		perror("Error\nError loading header image.\n");
		exit(EXIT_FAILURE);
	}
}

static void	init_objects(t_game_data *game_data)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./assets/item.xpm";
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

void	init_sprites(t_game_data *gd)
{
	char	*relative_path;
	int		img_width;
	int		img_height;

	gd->sprites = malloc(sizeof(t_sprites));
	if (gd->sprites == NULL)
	{
		perror("Error\nMalloc failed for game_data.sprites\n");
		exit(EXIT_FAILURE);
	}
	relative_path = "./assets/bg.xpm";
	gd->sprites->bg = mlx_xpm_file_to_image(gd->mlx,
			relative_path, &img_width, &img_height);
	if (gd->sprites->bg == NULL)
	{
		perror("Error\nError loading background image.\n");
		exit(EXIT_FAILURE);
	}
	resize_image(gd, img_width, img_height);
	init_walls_and_header(gd);
	init_objects(gd);
	init_sprites_player(gd);
	load_animations(gd);
}
