/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:21:22 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 13:51:07 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_cmds_size(t_cmd_container *cmd_container)
{
	size_t	size;

	if (cmd_container->cmds == NULL)
		return (0);
	size = 0;
	while (cmd_container->cmds[size] != NULL)
		size++;
	return (size);
}
