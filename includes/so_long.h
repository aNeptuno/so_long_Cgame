/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:24:42 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 19:44:35 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define MAX_ROWS 1080
# define MAX_COLS 1920
# define BUFFER_SIZE 1024
# define IMG_W 32
# define IMG_H 32
# define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97

typedef struct s_sprites
{
	void	*bg;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*object;
	void	*obstacle;
	void	*collectable;
	void	*exit;
	void	*enemy;
}				t_sprites;

typedef struct s_game_data
{
	char		**map;
	char		*file_content;
	int			fd;
	int			cols;
	int			rows;
	int			is_map_valid;
	int			size_x;
	int			size_y;
	t_sprites	*sprites;
	int			moves_count;

}	t_game_data;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*window;

}	t_mlx_data;

// Libft functions (utils)
int		ft_strlen(const char *str);
void	ft_putstr(char *s);
char	*ft_strstr(const char *haystack, const char *needle);
void	*my_realloc(void *ptr, size_t newsize, size_t oldsize);
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t len);

// Debugging
void	*my_malloc(size_t size);

// Map validation
void	get_cols(t_game_data *game_data);
void	get_rows(t_game_data *game_data);
void	is_square(t_game_data *game_data);
void	check_limits(t_game_data *game_data, char **map_candidate);
void	validate_map(t_game_data *game_data);

// Initialization
void	init_sprites(t_game_data *game_data, t_mlx_data *mlx_data);
void	put_images(t_game_data *game_data, t_mlx_data *mlx_data);

#endif