/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:14:59 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 15:53:49 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_program(t_shell *shell, char *program_path, t_cmd *cmd)
{
	int		status;

	if (cmd->pid == -1)
		cmd->pid = fork();
	if (cmd->pid == -1)
		put_error("minishell", "fork error", strerror(errno));
	else if (cmd->pid > 0 && !cmd->piped)
	{
		waitpid(cmd->pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->exit_status = 128 + WTERMSIG(status);
	}
	else if (execve(program_path, cmd->args, shell->env) == -1)
		put_error("minishell", "execve error", strerror(errno));
}
