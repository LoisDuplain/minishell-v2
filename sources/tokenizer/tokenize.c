/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 19:37:27 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	tokenize(t_cmd_container *cmd_container)
{
	size_t	line_length;

	if (!all_quotes_are_closed(cmd_container->line))
	{
		put_error("minishell", "error", "unclosed quote detected");
		return (FALSE);
	}
	line_length = ft_strlen(cmd_container->line);
	while (cmd_container->readed_index < line_length)
	{
		dispatch_tokenizing(cmd_container,
			cmd_container->line[cmd_container->readed_index]);
		cmd_container->readed_index++;
	}
	next_token(cmd_container);
	if (cmd_container->tokens != NULL)
		next_cmd(cmd_container);
	if (!all_cmds_are_filled(cmd_container))
	{
		destroy_cmd_container(cmd_container);
		return (FALSE);
	}
	return (TRUE);
}
