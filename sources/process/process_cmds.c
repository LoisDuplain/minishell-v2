/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/20 14:54:19 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_cmd(t_shell *shell, char **cmd, size_t cmd_len)
{
	char	**args;
	size_t	cmd_part_index;

	args = NULL;
	cmd_part_index = 0;
	while (cmd_part_index < cmd_len)
	{
		args = ft_add_str_to_str_array(args,
				ft_strdup(cmd[cmd_part_index], FALSE), TRUE);
		cmd_part_index++;
	}
	if (get_builtin(ft_tolower(args[0])) != NULL)
		get_builtin(ft_tolower(args[0]))(shell, args);
	ft_destroy_string_array(&args);
}

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
