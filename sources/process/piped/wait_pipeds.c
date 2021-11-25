/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_pipeds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:11:12 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 14:52:21 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_pipeds(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*current;
	int		status;

	current = cmd;
	while (current != NULL && (current->piped || current->prev->piped)
		&& current->pid != -1)
	{
		waitpid(current->pid, &status, 0);
		current = current->next;
		if (!(current != NULL && (current->piped || current->prev->piped)
				&& current->pid != -1))
		{
			if (WIFEXITED(status))
				shell->exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				shell->exit_status = 128 + WTERMSIG(status);
		}
	}
}
