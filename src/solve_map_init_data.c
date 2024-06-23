/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map_init_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 14:46:52 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/23 14:47:11 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_data(t_game_data *gd)
{
	gd->new_move = 'D';
	gd->player_moves = 0;
	gd->player_items = 0;
	gd->map_items = 0;
	gd->min_moves = 100;
	gd->move_up = 0;
	gd->move_down = 0;
	gd->move_left = 0;
	gd->move_right = 0;
	gd->update_counter = 0;
	gd->game_ended = 0;
}
