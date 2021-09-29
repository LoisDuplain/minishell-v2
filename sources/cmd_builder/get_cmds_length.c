/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:54:44 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/29 16:55:59 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_cmds_length(t_cmd_builder *cmd_builder)
{
	size_t	index;

	if (cmd_builder->cmds == NULL)
		return (0);
	index = 0;
	while (cmd_builder->cmds[index] != NULL)
		index++;
	return (index);
}
