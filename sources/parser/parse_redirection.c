/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:22:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/19 13:22:30 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_redirection(t_cmd_builder *cmd_builder, char redirect)
{
	next_cmd_part(cmd_builder);
	cmd_builder->cmd_part = ft_append_char_to_str(
			cmd_builder->cmd_part, redirect);
	if (cmd_builder->line[cmd_builder->readed_index + 1] == redirect)
	{
		cmd_builder->readed_index++;
		cmd_builder->cmd_part = ft_append_char_to_str(
				cmd_builder->cmd_part, redirect);
	}
	next_cmd_part(cmd_builder);
}
