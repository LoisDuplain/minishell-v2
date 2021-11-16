/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:14:59 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/16 16:50:21 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_program(t_shell *shell, char *program_path, t_cmd *cmd)
{
	int		status;

	cmd->pid = fork();
	if (cmd->pid == -1)
		put_error("minishell", "fork error", strerror(errno));
	else if (cmd->pid > 0 && !cmd->piped)
		waitpid(cmd->pid, &status, 0);
	else
	{
		if (execve(program_path, cmd->args, shell->env) == -1)
			put_error("minishell", "execve error", strerror(errno));
	}
}
