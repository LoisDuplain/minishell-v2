/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:22:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 13:44:51 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_redirection(t_cmd_container *cmd_container, char redirect)
{
	next_cmd_part(cmd_container);
	cmd_container->cmd_part = ft_append_char_to_str(
			cmd_container->cmd_part, redirect);
	if (cmd_container->line[cmd_container->readed_index + 1] == redirect)
	{
		cmd_container->readed_index++;
		cmd_container->cmd_part = ft_append_char_to_str(
				cmd_container->cmd_part, redirect);
	}
	next_cmd_part(cmd_container);
}
