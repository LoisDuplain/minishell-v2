/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:57:25 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:00:35 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenize_quote(t_cmd_container *cmd_container, char quote)
{
	char	current_char;

	cmd_container->token = ft_append_char_to_str(cmd_container->token,
			quote);
	cmd_container->readed_index++;
	current_char = cmd_container->line[cmd_container->readed_index];
	while (current_char && current_char != quote)
	{
		cmd_container->token = ft_append_char_to_str(cmd_container->token,
				current_char);
		cmd_container->readed_index++;
		current_char = cmd_container->line[cmd_container->readed_index];
	}
	cmd_container->token = ft_append_char_to_str(cmd_container->token,
			quote);
}
