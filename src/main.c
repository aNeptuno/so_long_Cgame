/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:32:07 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/22 15:43:21 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game_data *mlx_data)
{
	if (mlx_data->window)
        mlx_destroy_window(mlx_data->mlx, mlx_data->window);
    if (mlx_data->mlx)
        mlx_destroy_display(mlx_data->mlx);
    free(mlx_data->mlx);
	ft_putstr("\033[1;31m");
	ft_putstr("\nNooo, you gave up :'c\n");
	ft_putstr("\033[0m\n");
	exit(EXIT_SUCCESS);
	return (0);
}

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

void	move_player(int coord_x, int coord_y, t_game_data *gd)
{
	char	c;
	c = gd->map[gd->player_y - coord_y][gd->player_x + coord_x];

	if (c != '1')
	{
		// cambio sprite en la posicion antigua por vacio
		gd->map[gd->player_y][gd->player_x] = '0';

		// guardo referencia a la posision
		gd->player_y -= coord_y;
		gd->player_x += coord_x;

		// cambio sprite en nueva posicion por player
		gd->map[gd->player_y][gd->player_x] = 'P';

		change_player_sprite(coord_x, coord_y, gd);
		gd->player_moves++;
		if (c == 'C')
			gd->player_items++;
		if (c == 'E')
		{
			printf("player tiems: %d, map items: %d\n",gd->player_items, gd->map_items);
			if (gd->player_items == gd->map_items && gd->player_moves <= gd->min_moves)
			{
				ft_putstr("\033[1;32m");
				printf("\nYou won! :D\nCollected items: %d | Total moves: %d \n", gd->player_items, gd->player_moves);
				ft_putstr("\033[0m\n");
			}
			else
			{
				ft_putstr("\033[1;31m");
				printf("\nYou lose :(\nCollected items: %d | Total moves: %d \n", gd->player_items, gd->player_moves);
				ft_putstr("\033[0m\n");
			}
		}
		mlx_clear_window(gd->mlx, gd->window);
		draw_bg(gd);
		put_map(gd, 0);
	}

}

int	key_hook_callback(int keycode, t_game_data *gd)
{
	if (keycode == ESC)
	{
		close_window(gd);
	}
	if (keycode == UP)
	{
		move_player(0, 1, gd);
	}
	if (keycode == DOWN)
	{
		move_player(0, -1, gd);
	}
	if (keycode == LEFT)
	{
		move_player(-1, 0, gd);
	}
	if (keycode == RIGHT)
	{
		move_player(1, 0, gd);
	}

	printf("keycode: %d\n",keycode);
	return (0);
}

void	init_mlx(t_game_data *gd)
{
	gd->mlx = mlx_init();
	if (gd->mlx == NULL)
	{
		perror("Error\nmlx init failed\n");
		exit(EXIT_FAILURE);
	}
	gd->window = mlx_new_window(gd->mlx, gd->size_x, gd->size_y, "so_long");
	if (gd->window == NULL)
	{
		mlx_destroy_display(gd->mlx);
		free(gd->mlx);
		exit(EXIT_FAILURE);
	}
}

void init_game_data(t_game_data *gd)
{
	gd->new_move = 'D';
	gd->player_moves = 0;
	gd->player_items = 0;
	gd->map_items = 0;
	gd->min_moves = 100;
}

int	main(int ac, char **av)
{
	t_game_data	game_data;

	if (ac == 2)
	{
		get_map(&game_data, av[1]);
		if (game_data.is_map_valid)
		{
			init_mlx(&game_data); // init mlx and window
			init_game_data(&game_data);
			init_sprites(&game_data);
			draw_bg(&game_data);
			put_map(&game_data, 1);
			mlx_hook(game_data.window, 17, 0L, close_window, &game_data);
			mlx_key_hook(game_data.window, key_hook_callback, &game_data);
			mlx_loop(game_data.mlx);
			perror("Error\nmlx loop failed\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
