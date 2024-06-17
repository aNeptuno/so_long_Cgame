/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:32:07 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 19:29:43 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Read the file and save it to a string
void	read_file(t_game_data *game_data)
{
	ssize_t	bytes_read;
	char	buffer[BUFFER_SIZE];
	size_t	content_size;
	char	*new_file_content;

	if (game_data->fd != -1)
	{
		content_size = 0;
		game_data->file_content = NULL;
		while ((bytes_read = read(game_data->fd, buffer, BUFFER_SIZE)) > 0)
		{
			new_file_content = my_realloc(game_data->file_content, content_size + bytes_read + 1, content_size);
			if (new_file_content == NULL)
			{
				perror("Error\nError allocating memory");
				free(game_data->file_content);
				game_data->file_content = NULL;
				return ;
			}
			game_data->file_content = new_file_content;
			ft_memcpy(game_data->file_content + content_size, buffer, bytes_read);
			content_size += bytes_read;
			game_data->file_content[content_size] = '\0';
        }
		if (bytes_read == -1)
		{
			perror("Error\nError reading file");
			free(game_data->file_content);
			game_data->file_content = NULL;
		}
		if (close(game_data->fd) == -1)
		{
			perror("Error\nError closing the file");
		}
	}
}

void	open_file(char	*file_path, t_game_data *game_data)
{
	int	fd;
	
	if (ft_strstr(file_path, ".ber"))
	{
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
		{
			perror("Error\nError opening the file");
		}
		game_data->fd = fd;
	}
	else
	{
		ft_putstr("Error\nIncorrect file extension (extension must be .ber)\n");
		game_data->fd = -1;
	}
	return ;
}

int	close_window(t_mlx_data *mlx_data)
{
	if (mlx_data->window)
        mlx_destroy_window(mlx_data->mlx, mlx_data->window);
    if (mlx_data->mlx)
        mlx_destroy_display(mlx_data->mlx);
    free(mlx_data->mlx);
	ft_putstr("Nooo, you gave up :'c\n");
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook_callback(int keycode, t_mlx_data *mlx_data)
{
	if (keycode == ESC)
	{
		close_window(mlx_data);
	}

	printf("keycode: %d\n",keycode);
	return (0);
}

void	init_mlx(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (mlx_data->mlx == NULL)
	{
		perror("Error\nmlx init failed\n");
		return ;
	}
	mlx_data->window = mlx_new_window(mlx_data->mlx, 800, 600, "so_long");
	if (mlx_data->window == NULL)
	{
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		return ;
	}
	mlx_hook(mlx_data->window, 17, 0L, close_window, mlx_data);
	mlx_key_hook(mlx_data->window, key_hook_callback, mlx_data);
}

int	main(int ac, char **av)
{
	t_game_data	game_data;
	t_mlx_data	mlx_data;

	if (ac == 2)
	{
		open_file(av[1], &game_data);
		read_file(&game_data);
		// test
		if (game_data.file_content)
		{
			puts(game_data.file_content);
			validate_map(&game_data);
			if (game_data.is_map_valid)
			{
				printf("Cols: %d\n", game_data.cols);
				printf("Rows: %d\n", game_data.rows);
				init_mlx(&mlx_data);
				init_sprites(&game_data, &mlx_data);
				put_images(&game_data, &mlx_data);
				mlx_loop(mlx_data.mlx);
			}
		}
	}
	return (0);
}
