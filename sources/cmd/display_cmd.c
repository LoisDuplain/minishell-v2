/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:52:55 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:01:24 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_cmd(t_cmd *cmd)
{
	size_t	cmd_part_index;

	if (cmd == NULL)
		return ;
	ft_putstr("Command ");
	ft_puti(cmd->index);
	if (cmd->piped)
		ft_putstr(" (piped)");
	ft_putstr_nl(":");
	if (cmd->tokens != NULL)
	{
		cmd_part_index = 0;
		while (cmd->tokens[cmd_part_index] != NULL)
		{
			ft_puti(cmd_part_index);
			ft_putstr(" - ");
			ft_putstr_nl(cmd->tokens[cmd_part_index]);
			cmd_part_index++;
		}
	}
	else
		ft_putstr_nl("(null)");
}
