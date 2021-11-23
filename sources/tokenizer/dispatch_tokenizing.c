/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_tokenizing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:41:02 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:05:08 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dispatch_tokenizing(t_cmd_container *cmd_container, char current_char)
{
	if (current_char == ' ')
		next_token(cmd_container);
	else if (current_char == '\'' || current_char == '\"')
		tokenize_quote(cmd_container, current_char);
	else if (current_char == '<' || current_char == '>')
		tokenize_redirection(cmd_container, current_char);
	else if (current_char == '|')
		tokenize_pipe(cmd_container);
	else if (current_char == ';')
		next_cmd(cmd_container);
	else
		cmd_container->token = ft_append_char_to_str(
				cmd_container->token, current_char);
}
