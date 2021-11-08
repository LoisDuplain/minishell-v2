/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:15:17 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/08 14:27:01 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_shell_redirection(t_shell_redir *shell_redir,
	int to_replace, int by)
{
	if (shell_redir->fd_backup != -1)
		stop_shell_redirection(shell_redir);
	shell_redir->fd_replaced = to_replace;
	shell_redir->fd_backup = dup(to_replace);
	dup2(by, to_replace);
	close(by);
}
