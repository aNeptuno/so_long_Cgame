/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:56:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/07/02 01:49:53 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Obtain pixel color in image
static int	get_pixel_color(void *img, int x, int y)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	return (*(int *)(data + (y * size_line + x * (bpp / 8))));
}

// Stablish pixel color in image
static void	set_pixel_color(void *img, int x, int y, int color)
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;

	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	*(int *)(data + (y * size_line + x * (bpp / 8))) = color;
}

static void	check_error_create_img(t_game_data *gd)
{
	if (!gd->sprites->bg_resized)
	{
		perror("Error\nFailed to create new bg image");
		exit(EXIT_FAILURE);
	}
}

// Function for resizing an image
void	resize_image(t_game_data *gd, int original_width, int original_height)
{
	int	x;
	int	y;
	int	old_x;
	int	old_y;

	gd->sprites->bg_resized = mlx_new_image(gd->mlx, gd->size_x, gd->size_y);
	check_error_create_img(gd);
	y = 0;
	while (y < gd->size_y)
	{
		x = 0;
		while (x < gd->size_x)
		{
			old_x = (int)(x * ((float)original_width / (float)gd->size_x));
			old_y = (int)(y * ((float)original_height / (float)gd->size_y));
			set_pixel_color(gd->sprites->bg_resized, x, y,
				get_pixel_color(gd->sprites->bg, old_x, old_y));
			x++;
		}
		y++;
	}
	return ;
}
