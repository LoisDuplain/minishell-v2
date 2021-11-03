/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 16:04:16 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 13:59:20 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t quantity, size_t type_size)
{
	void	*result;

	result = malloc(quantity * type_size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, quantity * type_size);
	return (result);
}
