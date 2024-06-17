/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:22:25 by adiban-i          #+#    #+#             */
/*   Updated: 2023/11/30 14:22:25 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*cb1;
	unsigned char	*cb2;

	cb1 = (unsigned char *)b1;
	cb2 = (unsigned char *)b2;
	i = 0;
	while (i < len)
	{
		if (cb1[i] != cb2[i])
			return (cb1[i] - cb2[i]);
		i++;
	}
	return (0);
}
