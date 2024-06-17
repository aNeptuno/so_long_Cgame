/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:51:12 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 18:07:44 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_char_of_map(char c)
{
	int	is_char;

	is_char = (c == 'C' || c == 'P' || c == 'E' || c == '\n');
	return (c == '1' || c == '0' || is_char);
}

static int	char_count(char charToCount, char *file)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file[i])
	{
		if (file[i] == charToCount)
			count++;
		i++;
	}
	return (count);
}

static int	validate_map_chars(t_game_data *game_data)
{
	int		i;
	int		file_len;
	char	*file;

	file_len = ft_strlen(game_data->file_content);
	i = 0;
	file = game_data->file_content;
	while (file[i] && is_char_of_map(file[i]))
		i++;
	if (i != file_len)
	{
		ft_putstr("Error\nMap contains forbbiden characters\n");
		return (0);
	}
	if (char_count('E', file) != 1 || char_count('P', file) != 1)
	{
		ft_putstr("Error\nMap doesnt have ONE character 'E' or 'P'\n");
		return (0);
	}
	if (char_count('C', file) == 0)
	{
		ft_putstr("Error\nMap doesnt at least ONE collectable 'C'\n");
		return (0);
	}
	return (1);
}

void	validate_map(t_game_data *game_data)
{
	if (!validate_map_chars(game_data))
		return ;
	get_cols(game_data);
	get_rows(game_data);
	if (!game_data->is_map_valid)
		return ;
	is_square(game_data);
	if (game_data->map != NULL)
		check_limits(game_data, game_data->map);
}
