/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 16:03:37 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_shell *shell)
{
	t_cmd_builder	*cmd_builder;
	char			current_char;

	if (!all_quotes_are_closed(shell->line))
	{
		put_error("minishell", "error", "unclosed quote detected.");
		return ;
	}
	cmd_builder = create_cmd_builder(shell->line);
	if (cmd_builder == NULL)
	{
		put_error("minishell", "error", "cmd_builder creation failed.");
		return ;
	}
	while (cmd_builder->readed_index < ft_strlen(cmd_builder->line))
	{
		current_char = cmd_builder->line[cmd_builder->readed_index];
		dispatch_parsing(cmd_builder, current_char);
		cmd_builder->readed_index++;
	}
	next_cmd(cmd_builder);
	display_cmd_builder(cmd_builder);
	process_cmds(shell, cmd_builder);
	destroy_cmd_builder(&cmd_builder);
}
