/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd_container.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:37:04 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:00:58 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd_container(t_cmd_container *cmd_container)
{
	cmd_container->line = NULL;
	cmd_container->readed_index = 0;
	cmd_container->cmds = NULL;
	cmd_container->tokens = NULL;
	cmd_container->token = NULL;
}
