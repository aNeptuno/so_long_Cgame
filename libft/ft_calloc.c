/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiban-i <adiban-i@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:45:37 by adiban-i          #+#    #+#             */
/*   Updated: 2023/11/30 14:45:37 by adiban-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*res;

	res = malloc(number * size);
	if (!res)
		return (NULL);
	ft_bzero(res, number * size);
	return (res);
}
