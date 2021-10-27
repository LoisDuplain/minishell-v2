/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/27 14:41:29 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_cmds(t_shell *shell, t_cmd_builder *cmd_builder)
{
	size_t	cmd_index;

	if (get_cmds_length(cmd_builder) <= 0)
		return ;
	cmd_index = 0;
	while (cmd_builder->cmds[cmd_index] != NULL)
	{
		process_cmd(shell, cmd_builder->cmds[cmd_index],
			ft_get_string_array_length(cmd_builder->cmds[cmd_index]));
		cmd_index++;
	}
}
