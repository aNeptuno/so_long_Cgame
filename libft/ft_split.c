/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:44:07 by adiban-i          #+#    #+#             */
/*   Updated: 2023/12/03 21:44:07 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || !s[i + 1]) && s[i] != c)
			size++;
		i++;
	}
	return (size);
}

static void	free_mem(char **res)
{
	int	i;

	i = -1;
	while (res[i++])
		free(res[i]);
	free(res);
}

static char	**init_result(char const *s, char c, char **res)
{
	size_t	begin;
	size_t	i;
	size_t	word;

	begin = 0;
	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || !s[i + 1]) && s[i] != c)
		{
			res[word] = ft_substr(s, begin, i - begin + 1);
			if (!res[word])
			{
				free_mem(res);
				return (NULL);
			}
			word++;
		}
		if (s[i] == c && (s[i + 1] != c || s[i + 1]))
			begin = i + 1;
		i++;
	}
	res[word] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**res;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	res = (char **)malloc((size + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = init_result(s, c, res);
	return (res);
}
