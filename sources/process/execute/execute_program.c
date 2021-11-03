/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:14:59 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 15:58:18 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_program(t_shell *shell, char *program_path, char **args)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		put_error("minishell", "fork error", strerror(errno));
	else if (pid > 0)
		waitpid(pid, &status, 0);
	else
	{
		if (execve(program_path, args, shell->env) == -1)
			put_error("minishell", "execve error", strerror(errno));
	}
	errno = 0;
}
