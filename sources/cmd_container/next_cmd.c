/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:15:08 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 16:34:23 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	next_cmd(t_cmd_container *cmd_container)
{
	size_t	cmds_size;
	t_cmd	**new_cmds;
	size_t	index;

	cmds_size = get_cmds_size(cmd_container);
	new_cmds = ft_calloc(cmds_size + 2, sizeof(t_cmd *));
	if (new_cmds == NULL)
		return ;
	next_cmd_part(cmd_container);
	index = 0;
	while (index < cmds_size)
	{
		new_cmds[index] = cmd_container->cmds[index];
		index++;
	}
	new_cmds[index] = create_cmd(index, cmd_container->cmd);
	if (index > 0)
		new_cmds[index]->prev = new_cmds[index - 1];
	if (index > 0)
		new_cmds[index - 1]->next = new_cmds[index];
	new_cmds[index + 1] = NULL;
	cmd_container->cmd = NULL;
	free(cmd_container->cmds);
	cmd_container->cmds = new_cmds;
}
