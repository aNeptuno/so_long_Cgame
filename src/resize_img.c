/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:56:35 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/22 12:09:55 by adiban-i         ###   ########.fr       */
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
    return *(int *)(data + (y * size_line + x * (bpp / 8)));
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

// Function for resizing an image
void	resize_image(t_game_data *gd, int original_width, int original_height)
{
    int x;
    int y;
    int new_x;
    int new_y;

    gd->sprites->bg_resized = mlx_new_image(gd->mlx, gd->size_x, gd->size_y);
    if (!gd->sprites->bg_resized )
    {
        perror("Error\nFailed to create new bg image");
        exit(EXIT_FAILURE);
    }

	y = 0;
	while (y < gd->size_y)
	{
		x = 0;
		while (x < gd->size_x)
		{
			new_x = x * original_width / gd->size_x;
            new_y = y * original_height / gd->size_y;
            set_pixel_color(gd->sprites->bg_resized , x, y, 
					get_pixel_color(gd->sprites->bg, new_x, new_y));
			x++;
		}
		y++;
	}
    return ;
}
