/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:22:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:05:19 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenize_redirection(t_cmd_container *cmd_container, char redirect)
{
	next_token(cmd_container);
	cmd_container->token = ft_append_char_to_str(
			cmd_container->token, redirect);
	if (cmd_container->line[cmd_container->readed_index + 1] == redirect)
	{
		cmd_container->readed_index++;
		cmd_container->token = ft_append_char_to_str(
				cmd_container->token, redirect);
	}
	next_token(cmd_container);
}
