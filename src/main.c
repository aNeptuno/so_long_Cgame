/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:32:07 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/23 14:47:24 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game_data *gd)
{
	if (gd->window)
		mlx_destroy_window(gd->mlx, gd->window);
	if (gd->mlx)
		mlx_destroy_display(gd->mlx);
	free(gd->mlx);
	if (!gd->game_ended)
	{
		ft_putstr("\033[1;31m");
		ft_putstr("\nNooo, you gave up :'c\n");
		ft_putstr("\033[0m\n");
	}
	else
	{
		ft_putstr("\033[1;33m");
		ft_putstr("\nThanks for playing ^^!\n");
		ft_putstr("\033[0m\n");
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int keycode, t_game_data *gd)
{
	if (keycode == ESC)
	{
		close_window(gd);
	}
	if (keycode == UP)
	{
		gd->move_up = 1;
	}
	else if (keycode == DOWN)
	{
		gd->move_down = 1;
	}
	else if (keycode == LEFT)
	{
		gd->move_left = 1;
	}
	else if (keycode == RIGHT)
	{
		gd->move_right = 1;
	}
	printf("keycode: %d\n",keycode);
	return (0);
}

int	key_release(int keycode, t_game_data *gd)
{
	if (keycode == LEFT)
		gd->move_left = 0;
	if (keycode == RIGHT)
		gd->move_right = 0;
	if (keycode == UP)
		gd->move_up = 0;
	if (keycode == DOWN)
		gd->move_down = 0;
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

int	main(int ac, char **av)
{
	t_game_data	game_data;

	if (ac == 2)
	{
		get_map(&game_data, av[1]);
		if (game_data.is_map_valid)
		{
			init_mlx(&game_data);
			init_game_data(&game_data);
			init_sprites(&game_data);
			draw_bg(&game_data);
			put_map(&game_data, 1);
			mlx_hook(game_data.window, 2, 1L<<0, key_press, &game_data);
			mlx_hook(game_data.window, 3, 1L<<1, key_release, &game_data);
			mlx_loop_hook(game_data.mlx, render_next_frame_loop, &game_data);
			mlx_loop(game_data.mlx);
			perror("Error\nmlx loop failed\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
