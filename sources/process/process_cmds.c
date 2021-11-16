/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/16 15:13:18 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_cmds(t_shell *shell, t_cmd_container *cmd_container)
{
	t_cmd	*current;

	if (get_cmds_size(cmd_container) <= 0)
		return ;
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		preprocess_cmd(shell, current);
		process_cmd(shell, current);
		stop_shell_redirection(&shell->out_redir);
		stop_shell_redirection(&shell->in_redir);
		current = current->next;
	}
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		if (current->piped)
		{
			close(current->pipe[0]);
			close(current->pipe[1]);
		}
		current = current->next;
	}
}
