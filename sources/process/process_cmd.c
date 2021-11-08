/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:41:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/08 14:39:52 by lduplain         ###   ########.fr       */
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
		if (is_redirection(cmd[cmd_part_index]))
		{
			cmd_part_index++;
			if (!dispatch_redirection(shell, cmd, cmd_len, cmd_part_index))
			{
				ft_destroy_string_array(&args);
				return ;
			}
		}
		else if (ft_strcmp(cmd[cmd_part_index], "|") != 0)
			args = ft_add_str_to_str_array(args,
					get_processed_arg(shell, cmd[cmd_part_index]), TRUE);
		cmd_part_index++;
	}
	execute_cmd(shell, args);
	ft_destroy_string_array(&args);
}
