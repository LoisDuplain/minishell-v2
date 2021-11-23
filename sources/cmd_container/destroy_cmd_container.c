/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_cmd_container.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:19:55 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:00:58 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*destroy_cmd_container(t_cmd_container *cmd_container)
{
	size_t	index;

	if (cmd_container != NULL)
	{
		free(cmd_container->line);
		cmd_container->line = NULL;
		cmd_container->readed_index = 0;
		index = 0;
		while (index < get_cmds_size(cmd_container))
		{
			destroy_cmd(cmd_container->cmds[index]);
			index++;
		}
		free(cmd_container->cmds);
		cmd_container->cmds = NULL;
		cmd_container->tokens = ft_destroy_string_array(&cmd_container->tokens);
		free(cmd_container->token);
		cmd_container->token = NULL;
	}
	return (NULL);
}
