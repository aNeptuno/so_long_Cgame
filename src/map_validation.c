/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:30:05 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 10:40:41 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_cols(t_game_data *game_data)
{
	int		cols;
	int		found;
	char	*file;

	file = game_data->file_content;
	cols = 0;
	found = 0;
	while (file[cols] && !found)
	{
		cols++;
		if (file[cols] == '\n')
			found = 1;
	}
	if (cols < 3 || cols > MAX_COLS)
	{
		game_data->is_map_valid = 0;
		return ;
	}
	game_data->cols = cols;
	game_data->is_map_valid = 1;
}

void	get_rows(t_game_data *game_data)
{
	int		i;
	int		rows;
	char	*file;

	file = game_data->file_content;
	i = 0;
	rows = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			rows++;
		i++;
	}
	rows++;
	if (rows < 3 || rows > MAX_ROWS)
	{
		game_data->is_map_valid = 0;
		return ;
	}
	game_data->rows = rows;
	game_data->is_map_valid = 1;
}

void	is_square(t_game_data *game_data)
{
	char	**split_file;
	int		i;

	split_file = ft_split(game_data->file_content, '\n');
	i = 0;
	while (i < game_data->rows)
	{
		if (ft_strlen(split_file[i]) != game_data->cols)
		{
			game_data->is_map_valid = 0;
			return ;
		}
		i++;
	}
	game_data->is_map_valid = 1;
	game_data->map = split_file;
	if (game_data->file_content)
		free(game_data->file_content);
}

int	check_horizontal(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '1')
			count++;
		i++;
	}
	if (count == ft_strlen(line))
		return (1);
	return (0);
}

void	check_limits(t_game_data *game_data, char	**map)
{
	int	i;
	int	is_valid;

	is_valid = check_horizontal(map[0]);
	is_valid = check_horizontal(map[game_data->rows - 1]);
	if (!is_valid)
	{
		ft_putstr("Error\nMap needs to have obstacles as limits!\n");
		game_data->is_map_valid = 0;
		return ;
	}
	i = 1;
	while (i < game_data->rows - 1)
	{
		is_valid = map[i][0] == '1' && map[i][game_data->cols -1] == '1';
		if (!is_valid)
		{
			ft_putstr("Error\nMap need to have obstacles as limits!\n");
			game_data->is_map_valid = 0;
			return ;
		}
		i++;
	}
	game_data->is_map_valid = 1;
}