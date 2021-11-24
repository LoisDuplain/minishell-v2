/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:15:08 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 14:12:49 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	next_cmd(t_cmd_container *cmd_container)
{
	size_t	cmds_size;
	t_cmd	**new_cmds;

	next_token(cmd_container);
	cmds_size = get_cmds_size(cmd_container);
	new_cmds = realloc_cmds(cmd_container);
	new_cmds[cmds_size] = create_cmd(cmds_size, cmd_container->tokens);
	if (cmds_size > 0)
		new_cmds[cmds_size]->prev = new_cmds[cmds_size - 1];
	if (cmds_size > 0)
		new_cmds[cmds_size - 1]->next = new_cmds[cmds_size];
	new_cmds[cmds_size + 1] = NULL;
	cmd_container->tokens = NULL;
	free(cmd_container->cmds);
	cmd_container->cmds = new_cmds;
}
