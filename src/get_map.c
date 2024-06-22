/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:43:20 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/22 19:47:39 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

// Read the file and save it to a string
static void	read_file(t_game_data *game_data)
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

static void	open_file(char	*file_path, t_game_data *game_data)
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

void	get_map(t_game_data *game_data, char *file_content)
{
	open_file(file_content, game_data);
	read_file(game_data);
	if (game_data->file_content)
	{
		puts(game_data->file_content);
		validate_map(game_data);
		if (game_data->is_map_valid)
		{
			printf("Cols: %d\n", game_data->cols);
			printf("Rows: %d\n", game_data->rows);
			game_data->size_x = game_data->cols * PIXELS;
			game_data->size_y = game_data->rows * PIXELS + HEADER_HEIGHT;
		}
	}
}
