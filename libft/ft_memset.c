/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:26:08 by adiban-i          #+#    #+#             */
/*   Updated: 2023/11/30 10:26:08 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	size_t			i;
	unsigned char	*cdst;

	cdst = (unsigned char *)dst;
	i = 0;
	while (i < len)
	{
		cdst[i] = (unsigned char)c;
		i++;
	}
	return (dst);
}
