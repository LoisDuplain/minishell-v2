/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:11:32 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/05 12:27:51 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	next_cmd(t_cmd_builder *cmd_builder)
{
	size_t	cmds_length;
	char	***new_cmds;
	size_t	index;

	cmds_length = get_cmds_length(cmd_builder);
	new_cmds = ft_calloc(cmds_length + 2, sizeof(char **));
	if (new_cmds == NULL)
		return ;
	next_cmd_part(cmd_builder);
	index = 0;
	while (index < cmds_length)
	{
		new_cmds[index] = cmd_builder->cmds[index];
		index++;
	}
	new_cmds[index] = cmd_builder->cmd;
	cmd_builder->cmd = NULL;
	new_cmds[index + 1] = NULL;
	free(cmd_builder->cmds);
	cmd_builder->cmds = new_cmds;
}
