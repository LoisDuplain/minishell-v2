/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:19:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/08 14:32:25 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	dispatch_redirection(t_shell *shell, char **cmd,
		size_t cmd_len, size_t p_index)
{
	if (p_index >= cmd_len)
		return (put_error("minishell", "syntax error", "redirection parsing"));
	if (ft_strcmp(cmd[p_index - 1], ">>") == 0
		|| ft_strcmp(cmd[p_index - 1], ">") == 0)
		return (start_file_redirection(&shell->out_redir, cmd[p_index],
				O_WRONLY | get_output_redirection_mode(cmd[p_index - 1])
				| O_CREAT, STDOUT_FILENO));
	else if (ft_strcmp(cmd[p_index - 1], "<<") == 0)
	{
		if (!read_until_keyword(cmd[p_index]))
			return (FALSE);
		return (start_file_redirection(&shell->in_redir, "read_until_buffer",
				O_RDONLY, STDIN_FILENO));
	}
	else if (ft_strcmp(cmd[p_index - 1], "<") == 0)
	{
		return (start_file_redirection(&shell->in_redir, cmd[p_index],
				O_RDONLY, STDIN_FILENO));
	}
	return (FALSE);
}
