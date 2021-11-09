/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:19:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 16:00:14 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	dispatch_redirection(t_shell *shell, t_cmd *cmd, size_t arg_index)
{
	if (arg_index >= cmd->size)
		return (put_error("minishell", "syntax error", "redirection parsing"));
	if (ft_strcmp(cmd->args[arg_index - 1], ">>") == 0
		|| ft_strcmp(cmd->args[arg_index - 1], ">") == 0)
		return (start_file_redirection(&shell->out_redir, cmd->args[arg_index],
				O_WRONLY | get_output_redirection_mode(cmd->args[arg_index - 1])
				| O_CREAT, STDOUT_FILENO));
	else if (ft_strcmp(cmd->args[arg_index - 1], "<<") == 0)
	{
		if (!read_until_keyword(cmd->args[arg_index]))
			return (FALSE);
		return (start_file_redirection(&shell->in_redir, "read_until_buffer",
				O_RDONLY, STDIN_FILENO));
	}
	else if (ft_strcmp(cmd->args[arg_index - 1], "<") == 0)
	{
		return (start_file_redirection(&shell->in_redir, cmd->args[arg_index],
				O_RDONLY, STDIN_FILENO));
	}
	return (FALSE);
}
