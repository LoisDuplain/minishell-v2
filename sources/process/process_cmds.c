/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 10:17:04 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(t_cmd *cmd)
{
	close(cmd->pipe[1]);
	if (cmd->piped && cmd->next == NULL)
		close(cmd->pipe[0]);
}

void	open_pipe(t_cmd *cmd)
{
	if (cmd->prev != NULL && cmd->prev->piped)
		if (cmd->in_redir.fd_backup == -1)
			dup2(cmd->prev->pipe[0], 0);
	if (cmd->next != NULL && cmd->piped)
		if (cmd->out_redir.fd_backup == -1)
			dup2(cmd->pipe[1], 1);
	close(cmd->pipe[0]);
	close(cmd->pipe[1]);
}

void	wait_pipeds(t_cmd *cmd)
{
	t_cmd	*current;
	int		status;

	current = cmd;
	while (current != NULL && current->piped && current->pid != -1)
	{
		waitpid(current->pid, &status, 0);
		current = current->next;
	}
}

t_cmd	*process_piped(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current != NULL && current->piped)
	{
		if (pipe(current->pipe) == -1)
			break ;
		current->pid = fork();
		if (current->pid == -1)
			put_error("minishell", "fork error", strerror(errno));
		else if (current->pid == 0)
		{
			parse_cmd(shell, current);
			open_pipe(current);
			execute_cmd(shell, current);
			exit(EXIT_SUCCESS);
		}
		close_pipe(current);
		current = current->next;
	}
	wait_pipeds(cmd);
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
			current = process_piped(shell, current);
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
