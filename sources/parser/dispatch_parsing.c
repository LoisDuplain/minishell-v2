/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:41:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/19 13:41:24 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dispatch_parsing(t_cmd_builder *cmd_builder, char current_char)
{
	if (current_char == '\'' || current_char == '\"')
		parse_quote(cmd_builder, current_char);
	else if (current_char == '<' || current_char == '>')
		parse_redirection(cmd_builder, current_char);
	else if (current_char == ' ')
		next_cmd_part(cmd_builder);
	else if (current_char == '|')
		parse_pipe(cmd_builder);
	else if (current_char == ';')
		next_cmd(cmd_builder);
	else
		cmd_builder->cmd_part = ft_append_char_to_str(
				cmd_builder->cmd_part, current_char);
}
