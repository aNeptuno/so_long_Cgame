/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 02:54:40 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/02 02:56:04 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_free(t_game_data *game_data, char *msg)
{
	perror("Error\n");
	ft_putstr(msg);
	free(game_data->file_content);
	game_data->file_content = NULL;
	return ;
}
