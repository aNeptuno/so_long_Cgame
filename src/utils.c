/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:32:46 by adiban-i          #+#    #+#             */
/*   Updated: 2024/06/17 10:39:22 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	k;
	int	needle_size;

	if (haystack != NULL && needle != NULL)
	{
		needle_size = ft_strlen(needle);
		i = 0;
		while (haystack[i])
		{
			j = 0;
			k = i;
			while (haystack[k] && needle[j] && haystack[k] == needle[j])
			{
				j++;
				k++;
			}
			if (j == needle_size)
				return ((char *)(haystack + i));
			i++;
		}
	}
	return (NULL);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

// Copy into dst from src "len" bytes
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char			*cdst;
	const char		*csrc;
	size_t			i;

	cdst = (char *)dst;
	csrc = (const char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cdst[i] = (char)csrc[i];
		i++;
	}
	return (dst);
}

// Works as realloc but it recibes the oldsize as a parameter
void	*my_realloc(void *ptr, size_t newsize, size_t oldsize)
{
	void	*newptr;

	if (ptr == NULL)
	{
		ptr = malloc(newsize);
		return (ptr);
	}
	else if (ptr != NULL && newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		newptr = malloc(newsize);
		if (newptr == NULL)
			return NULL;
		if (newsize < oldsize)
			oldsize = newsize;
		ft_memcpy(newptr, ptr, oldsize);
		return (ptr);
	}
}

// Split
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if ((int)start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while ((int)start < ft_strlen(s) && i < len && s[start])
	{
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

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
