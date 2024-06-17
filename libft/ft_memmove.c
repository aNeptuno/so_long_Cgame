/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:06:33 by adiban-i          #+#    #+#             */
/*   Updated: 2023/11/30 13:06:33 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;
	int		i;

	cdst = (char *)dst;
	csrc = (char *)src;
	if (cdst < csrc)
	{
		i = 0;
		while (i < (int)len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	if (cdst > csrc)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			cdst[i] = csrc[i];
			i--;
		}
	}
	return (dst);
}
