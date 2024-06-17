/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:24:42 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 12:47:23 by adiban-i         ###   ########.fr       */
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

typedef struct s_game_data
{
	char	**map;
	char	*file_content;
	int		fd;
	int		cols;
	int		rows;
	int		is_map_valid;

}	t_game_data;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*window;

}	t_mlx_data;

// Libft functions (utils)
int		ft_strlen(const char *str);
void	ft_putstr(char *s);
char	*ft_strstr(const char *haystack, const char *needle);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*my_realloc(void *ptr, size_t newsize, size_t oldsize);
char	**ft_split(char const *s, char c);

// Debugging
void	*my_malloc(size_t size);

// Map validation
int		is_char_of_map(char c);	
void	get_cols(t_game_data *game_data);
void	get_rows(t_game_data *game_data);
void	is_square(t_game_data *game_data);
int		char_count(char charToCount, char *file);
int		validate_map_chars(t_game_data *game_data);
int		check_horizontal(char *line);
void	check_limits(t_game_data *game_data, char **map_candidate);
void	validate_map(t_game_data *game_data);

#endif