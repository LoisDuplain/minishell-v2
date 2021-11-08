/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_shell_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:17:48 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/08 14:18:10 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	stop_shell_redirection(t_shell_redir *shell_redir)
{
	if (shell_redir->fd_backup == -1)
		return ;
	dup2(shell_redir->fd_backup, shell_redir->fd_replaced);
	close(shell_redir->fd_backup);
	shell_redir->fd_backup = -1;
	shell_redir->fd_replaced = -1;
}
