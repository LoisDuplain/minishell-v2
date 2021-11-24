/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_cmds_are_filled.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:39 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 14:15:47 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	all_cmds_are_filled(t_cmd_container *cmd_container)
{
	size_t	cmd_index;

	cmd_index = 0;
	while (cmd_index < get_cmds_size(cmd_container))
	{
		if (cmd_container->cmds[cmd_index]->tokens == NULL)
		{
			put_error("minishell", "error", "empty command found");
			return (FALSE);
		}
		cmd_index++;
	}
	return (TRUE);
}
