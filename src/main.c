/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:32:07 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/18 19:22:38 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void GameOver()
{
	printf("\033[1;31m");

    // Dibujo en rojo que dice "GAME OVER"
    printf("  ████████  ████    ████  ████████  \n");
    printf("██          ████  ████    ██      ██\n");
    printf("██  ██████  ██  ██  ██  ██████  ████\n");
    printf("██      ██  ██      ██      ██    ██\n");
    printf("  ████████  ██      ██  ██████    ██\n");

    // Restablecer el color a la configuración predeterminada
    printf("\033[0m\n");
}

int	close_window(t_game_data *mlx_data)
{
	if (mlx_data->window)
        mlx_destroy_window(mlx_data->mlx, mlx_data->window);
    if (mlx_data->mlx)
        mlx_destroy_display(mlx_data->mlx);
    free(mlx_data->mlx);
	ft_putstr("\033[1;31m");
	ft_putstr("Nooo, you gave up :'c\n");
	ft_putstr("\033[0m\n");
	//GameOver();
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook_callback(int keycode, t_game_data *mlx_data)
{
	if (keycode == ESC)
	{
		close_window(mlx_data);
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


int	main(int ac, char **av)
{
	t_game_data	game_data;

	if (ac == 2)
	{
		get_map(&game_data, av[1]);
		if (game_data.is_map_valid)
		{
			init_mlx(&game_data); // init mlx and window
			init_sprites(&game_data);
			put_bg(&game_data);
			put_map(&game_data);
			mlx_hook(game_data.window, 17, 0L, close_window, &game_data);
			mlx_key_hook(game_data.window, key_hook_callback, &game_data);
			mlx_loop(game_data.mlx);
			perror("Error\nmlx loop failed\n");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
