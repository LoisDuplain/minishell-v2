/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_piped_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:08:05 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 19:10:18 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_piped_redirections(t_cmd *cmd)
{
	if (cmd->prev != NULL && cmd->prev->piped)
		if (cmd->in_redir.fd_backup == -1)
			dup2(cmd->prev->pipe[0], 0);
	if (cmd->next != NULL && cmd->piped)
		if (cmd->out_redir.fd_backup == -1)
			dup2(cmd->pipe[1], 1);
	if (cmd->piped)
	{
		close(cmd->pipe[0]);
		close(cmd->pipe[1]);
	}
}
