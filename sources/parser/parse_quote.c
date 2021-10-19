/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:57:25 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/19 13:23:54 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_quote(t_cmd_builder *cmd_builder, char quote)
{
	char	current_char;

	cmd_builder->readed_index++;
	current_char = cmd_builder->line[cmd_builder->readed_index];
	while (current_char && current_char != quote)
	{
		cmd_builder->cmd_part = ft_append_char_to_str(cmd_builder->cmd_part,
				current_char);
		cmd_builder->readed_index++;
		current_char = cmd_builder->line[cmd_builder->readed_index];
	}
}
