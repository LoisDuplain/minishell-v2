/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 15:24:07 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_in_execution(t_shell *shell, t_bool state)
{
	shell->is_in_execution = state;
	if (state)
		signal(SIGQUIT, ctrl_backslash_signal);
	else
		signal(SIGQUIT, SIG_IGN);
}

void	process_cmds(t_shell *shell, t_cmd_container *cmd_container)
{
	t_cmd	*current;

	if (get_cmds_size(cmd_container) <= 0)
		return ;
	set_in_execution(shell, TRUE);
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		if (current->piped)
			current = process_pipeds(shell, current);
		else
		{
			if (current->prev != NULL && current->prev->piped)
				start_shell_redirection(&current->in_redir,
					STDIN_FILENO, current->prev->pipe[0]);
			parse_cmd(shell, current);
			execute_cmd(shell, current);
			stop_shell_redirection(&current->out_redir);
			stop_shell_redirection(&current->in_redir);
			current = current->next;
		}
	}
	set_in_execution(shell, FALSE);
	destroy_cmd_container(cmd_container);
}
