/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:41:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/16 16:18:53 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_cmd(t_shell *shell, t_cmd *cmd)
{
	char	**args;
	size_t	arg_index;

	args = NULL;
	arg_index = 0;
	while (arg_index < cmd->size)
	{
		if (is_redirection(cmd->args[arg_index]))
		{
			arg_index++;
			if (!dispatch_redirection(shell, cmd, arg_index))
			{
				ft_destroy_string_array(&args);
				return ;
			}
		}
		else
			args = ft_add_str_to_str_array(args,
					get_processed_arg(shell, cmd->args[arg_index]), TRUE);
		arg_index++;
	}
	execute_cmd(shell, cmd);
	ft_destroy_string_array(&args);
}
