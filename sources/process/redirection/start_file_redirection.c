/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_file_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:30:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 12:07:32 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	start_file_redirection(t_shell_redir *shell_redir, char *file,
		int mode, int to_replace)
{
	int	file_fd;

	file_fd = open(file, mode, 0644);
	if (file_fd == -1)
		return (put_error("minishell", file, "can't open"));
	start_shell_redirection(shell_redir, to_replace, file_fd);
	return (TRUE);
}
