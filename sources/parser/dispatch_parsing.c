/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:41:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 13:38:58 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dispatch_parsing(t_cmd_container *cmd_container, char current_char)
{
	if (current_char == '\'' || current_char == '\"')
		parse_quote(cmd_container, current_char);
	else if (current_char == '<' || current_char == '>')
		parse_redirection(cmd_container, current_char);
	else if (current_char == ' ')
		next_cmd_part(cmd_container);
	else if (current_char == '|')
		parse_pipe(cmd_container);
	else if (current_char == ';')
		next_cmd(cmd_container);
	else
		cmd_container->cmd_part = ft_append_char_to_str(
				cmd_container->cmd_part, current_char);
}
