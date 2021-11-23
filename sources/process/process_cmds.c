/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 11:57:31 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			// dprintf(1, "Next of %s\n", current->tokens[0]);
			if (current->prev == NULL)
				close(current->pipe[1]);
			else if (current->prev != NULL && current->next != NULL)
			{
				close(current->prev->pipe[0]);
				close(current->pipe[1]);
			}
			else if (current->prev != NULL && current->next == NULL)
			{
				close(current->pipe[0]);
				close(current->pipe[1]);
			}
			current = current->next;
		}
		else
		{
			if (current->prev == NULL)
			{
				dup2(current->pipe[1], 1);
				close(current->pipe[0]);
				close(current->pipe[1]);
			}
			else if (current->prev != NULL && current->next != NULL)
			{
				dup2(current->prev->pipe[0], 0);
				dup2(current->pipe[1], 1);
				close(current->pipe[0]);
				close(current->pipe[1]);
			}
			else if (current->prev != NULL && current->next == NULL)
			{
				dup2(current->prev->pipe[0], 0);
				close(current->pipe[0]);
				close(current->pipe[1]);
			}
			parse_cmd(shell, current);
			execute_cmd(shell, current);
			exit(EXIT_SUCCESS);
		}
	}
	int status;
	current = cmd;
	while (current != NULL && current->piped)
	{
		// dprintf(1, "Wait1 %s\n", current->tokens[0]);
		waitpid(current->pid, &status, 0);
		// dprintf(1, "Waited1 %s\n", current->tokens[0]);
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
			// dprintf(1, "Parse %s\n", current->tokens[0]);
			parse_cmd(shell, current);
			// dprintf(1, "Parsed %s\n", current->tokens[0]);
			if (current->prev != NULL && current->prev->piped)
			{
				// dprintf(1, "Redirect %s\n", current->tokens[0]);
				start_shell_redirection(&current->in_redir, STDIN_FILENO, current->prev->pipe[0]);
				// dprintf(1, "Redirected %s\n", current->tokens[0]);
			}
			// dprintf(1, "Execute %s\n", current->tokens[0]);
			execute_cmd(shell, current);
			// dprintf(1, "Executed %s\n", current->tokens[0]);
			stop_shell_redirection(&current->out_redir);
			stop_shell_redirection(&current->in_redir);
			current = current->next;
		}
	}
}
