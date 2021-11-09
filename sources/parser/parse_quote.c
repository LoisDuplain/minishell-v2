/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:57:25 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 12:57:07 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_quote(t_cmd_container *cmd_container, char quote)
{
	char	current_char;

	cmd_container->cmd_part = ft_append_char_to_str(cmd_container->cmd_part,
			quote);
	cmd_container->readed_index++;
	current_char = cmd_container->line[cmd_container->readed_index];
	while (current_char && current_char != quote)
	{
		cmd_container->cmd_part = ft_append_char_to_str(cmd_container->cmd_part,
				current_char);
		cmd_container->readed_index++;
		current_char = cmd_container->line[cmd_container->readed_index];
	}
	cmd_container->cmd_part = ft_append_char_to_str(cmd_container->cmd_part,
			quote);
}
