/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:12:58 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/16 15:13:25 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	preprocess_cmd(t_shell *shell, t_cmd *cmd)
{
	if (cmd->prev != NULL && cmd->prev->piped)
		start_shell_redirection(&shell->in_redir, STDIN_FILENO,
			cmd->prev->pipe[0]);
	if (cmd->piped)
	{
		pipe(cmd->pipe);
		start_shell_redirection(&shell->out_redir, STDOUT_FILENO, cmd->pipe[1]);
	}
}
