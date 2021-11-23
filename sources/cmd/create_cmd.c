/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:07:27 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:01:24 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*create_cmd(size_t index, char **args)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->index = index;
	cmd->tokens = args;
	cmd->size = ft_get_string_array_length(args);
	cmd->prev = NULL;
	cmd->next = NULL;
	cmd->pid = -1;
	cmd->out_redir.fd_backup = -1;
	cmd->out_redir.fd_replaced = -1;
	cmd->in_redir.fd_backup = -1;
	cmd->in_redir.fd_replaced = -1;
	return (cmd);
}
