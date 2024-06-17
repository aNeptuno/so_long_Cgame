/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:45:17 by adiban-i          #+#    #+#             */
/*   Updated: 2023/11/30 12:45:17 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

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
