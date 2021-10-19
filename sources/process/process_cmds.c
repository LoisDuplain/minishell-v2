/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/19 16:51:59 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_cmd(char **cmd, size_t cmd_len)
{
	char	**args;
	size_t	cmd_part_index;
	int		dest_fd;

	args = NULL;
	cmd_part_index = 0;
	while (cmd_part_index < cmd_len)
	{
		if (ft_strcmp(cmd[cmd_part_index], ">") == 0)
		{
			cmd_part_index++;
			if (cmd_part_index >= cmd_len)
				break ;
			dest_fd = open(cmd[cmd_part_index], O_WRONLY | O_TRUNC | O_CREAT, 0644);
			if (dest_fd == -1)
				break ;
			int backup = dup(STDOUT_FILENO);
			dup2(dest_fd, STDOUT_FILENO);
			close(dest_fd);
			ft_putstr_nl(cmd[0]);
			dup2(backup, STDOUT_FILENO);
			close(backup);
		}
		else
			args = ft_add_str_to_str_array(args, cmd[cmd_part_index], TRUE);
		cmd_part_index++;
	}
}

void	process_cmds(t_cmd_builder *cmd_builder)
{
	size_t	cmd_index;

	if (get_cmds_length(cmd_builder) <= 0)
		return ;
	cmd_index = 0;
	while (cmd_builder->cmds[cmd_index] != NULL)
	{
		process_cmd(cmd_builder->cmds[cmd_index],
			ft_get_string_array_length(cmd_builder->cmds[cmd_index]));
		cmd_index++;
	}
}
