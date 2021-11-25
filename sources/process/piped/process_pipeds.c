/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipeds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:12:09 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 14:36:44 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*process_pipeds(t_shell *shell, t_cmd *cmd)
{
	t_cmd	*current;

	current = cmd;
	while (current != NULL && (current->piped || current->prev->piped))
	{
		if (current->piped)
			if (pipe(current->pipe) == -1)
				break ;
		current->pid = fork();
		if (current->pid == -1)
			put_error("minishell", "fork error", strerror(errno));
		else if (current->pid == 0)
		{
			parse_cmd(shell, current);
			start_piped_redirections(current);
			execute_cmd(shell, current);
			exit(EXIT_SUCCESS);
		}
		if (current->piped)
			close_pipe(current);
		current = current->next;
	}
	wait_pipeds(shell, cmd);
	return (current);
}
