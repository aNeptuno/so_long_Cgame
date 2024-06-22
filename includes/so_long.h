/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:24:42 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/22 20:13:29 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define MAX_ROWS 100
# define MAX_COLS 100
# define BUFFER_SIZE 1024
# define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define PIXELS 32
# define HEADER_HEIGHT 50

/// @brief Structure for game sprites (mlx_xpm_file_to_image)
typedef struct s_sprites
{
	void	*bg;
	void	*bg_resized;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*obstacle;
	void	*collectable;
	void	*exit;
	void	*enemy;
	void	*header;
}				t_sprites;

/// @brief Structure for saving game data
/**
 * @file_content: Content of the .ber file.
 * @fd: File descriptor for the .ber file.
 * @map: 2D array representing the game map.
 * @cols: Number of columns in the map.
 * @rows: Number of rows in the map.
 * @is_map_valid: Flag indicating if the map is valid.
 * @mlx: Pointer to mlx connection.
 * @window: Window created by mlx.
 * @size_x: Width of the window in pixels (cols * 32).
 * @size_y: Height of the window in pixels (rows * 32).
 * @sprites: Pointer to the sprites structure for the game.
 * @player_moves: Counter for the number of moves made by the player.
 * @player_x: player position in x.
 * @player_y: player position in y.
 * @new_move: char representing new_move direction: U (up), D(down), L(left), R(right).
 */
typedef struct s_game_data
{
	char		*file_content;
	int			fd;
	char		**map;
	int			cols;
	int			rows;
	int			is_map_valid;
	void		*mlx;
	void		*window;
	int			size_x;
	int			size_y;
	int			map_items;
	int			min_moves;
	t_sprites	*sprites;
	int			player_moves;
	int			player_x;
	int			player_y;
	char		new_move;
	int			player_items;
}	t_game_data;

// Libft functions (utils)
int		ft_strlen(const char *str);
void	ft_putstr(char *s);
char	*ft_strstr(const char *haystack, const char *needle);
void	*my_realloc(void *ptr, size_t newsize, size_t oldsize);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char	*ft_itoa(int n);

// Debugging
void	*my_malloc(size_t size);

// Map validation
void	get_cols(t_game_data *game_data);
void	get_rows(t_game_data *game_data);
void	get_map_matrix(t_game_data *game_data);
void	check_limits(t_game_data *game_data);
void	validate_map(t_game_data *game_data);

// Game initialization
void	get_map(t_game_data *game_data, char *file_content);
void	resize_image(t_game_data *gd, int original_width, int original_height);
void	init_sprites(t_game_data *game_data);
void	put_map(t_game_data *gd, int init);
void 	draw_bg(t_game_data *gd);

#endif