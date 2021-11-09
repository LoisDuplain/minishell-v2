/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:41:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 16:46:55 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	**realloc_cmds(t_cmd_container *cmd_container)
{
	size_t	cmds_size;
	t_cmd	**new_cmds;
	size_t	index;

	cmds_size = get_cmds_size(cmd_container);
	new_cmds = ft_calloc(cmds_size + 2, sizeof(t_cmd *));
	if (new_cmds == NULL)
		return (NULL);
	index = 0;
	while (index < cmds_size)
	{
		new_cmds[index] = cmd_container->cmds[index];
		index++;
	}
	new_cmds[index + 1] = NULL;
	return (new_cmds);
}
