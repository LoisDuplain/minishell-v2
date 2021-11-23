/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 12:12:05 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(t_cmd *cmd)
{
	if (cmd->prev == NULL)
		close(cmd->pipe[1]);
	else if (cmd->prev != NULL && cmd->next != NULL)
	{
		close(cmd->prev->pipe[0]);
		close(cmd->pipe[1]);
	}
	else if (cmd->prev != NULL && cmd->next == NULL)
	{
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
	}
}

t_cmd	*process_piped(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current != NULL && current->piped)
	{
		pipe(current->pipe); // Handle error
		current->pid = fork();
		if (current->pid == -1)
			put_error("minishell", "fork error", strerror(errno));
		else if (current->pid > 0)
		{
			close_pipe(current);
			current = current->next;
		}
		else
		{
			if (current->prev != NULL && current->prev->piped)
				start_shell_redirection(&current->in_redir, STDIN_FILENO, current->prev->pipe[0]);
			start_shell_redirection(&current->out_redir, STDOUT_FILENO, current->pipe[1]);
			parse_cmd(shell, current);
			execute_cmd(shell, current);
			exit(EXIT_SUCCESS);
		}
	}
	int status;
	current = cmd;
	while (current != NULL && current->piped)
	{
		waitpid(current->pid, &status, 0);
		current = current->next;
	}
	return (current);
}

void	process_cmds(t_shell *shell, t_cmd_container *cmd_container)
{
	t_cmd	*current;

	if (get_cmds_size(cmd_container) <= 0)
		return ;
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		if (current->piped)
		{
			current = process_piped(shell, current);
		}
		else
		{
			if (current->prev != NULL && current->prev->piped)
				start_shell_redirection(&current->in_redir, STDIN_FILENO, current->prev->pipe[0]);
			parse_cmd(shell, current);
			execute_cmd(shell, current);
			stop_shell_redirection(&current->out_redir);
			stop_shell_redirection(&current->in_redir);
			current = current->next;
		}
	}
}
