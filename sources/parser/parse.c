/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 15:32:35 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_cmd_container *cmd_container)
{
	size_t	line_length;

	if (!all_quotes_are_closed(cmd_container->line))
	{
		put_error("minishell", "error", "unclosed quote detected");
		return ;
	}
	line_length = ft_strlen(cmd_container->line);
	while (cmd_container->readed_index < line_length)
	{
		dispatch_parsing(cmd_container,
			cmd_container->line[cmd_container->readed_index]);
		cmd_container->readed_index++;
	}
	next_cmd(cmd_container);
	display_cmd_container(cmd_container);
}
