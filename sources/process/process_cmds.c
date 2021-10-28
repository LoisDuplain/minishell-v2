/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/28 14:23:44 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	preprocess_cmd(t_shell *shell, char ***cmds, size_t cmd_index)
{
	int		count;
	char	**cmd;
	size_t	cmd_size;

	count = 1;
	cmd = cmds[cmd_index];
	cmd_size = ft_get_string_array_length(cmd);
	if (ft_strcmp(cmd[cmd_size - 1], "|") == 0 && cmds[cmd_index + 1] != NULL)
		count += preprocess_cmd(shell, cmds, cmd_index + 1);
	process_cmd(shell, cmd, cmd_size);
	return (count);
}

void	process_cmds(t_shell *shell, t_cmd_builder *cmd_builder)
{
	size_t	cmd_index;
	char	**cmd;
	size_t	cmd_size;

	if (get_cmds_length(cmd_builder) <= 0)
		return ;
	cmd_index = 0;
	while (cmd_builder->cmds[cmd_index] != NULL)
	{
		cmd = cmd_builder->cmds[cmd_index];
		cmd_size = ft_get_string_array_length(cmd);
		if (ft_strcmp(cmd[cmd_size - 1], "|") == 0)
			cmd_index += preprocess_cmd(shell, cmd_builder->cmds, cmd_index);
		else
		{
			process_cmd(shell, cmd, cmd_size);
			cmd_index++;
		}
	}
}
