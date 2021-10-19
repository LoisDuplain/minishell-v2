/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cmd_builder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:33:31 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/19 13:36:15 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_cmd_builder(t_cmd_builder *cmd_builder)
{
	size_t	cmd_index;
	size_t	cmd_part_index;

	cmd_index = 0;
	while (cmd_builder->cmds[cmd_index] != NULL)
	{
		ft_putstr("Command ");
		ft_puti(cmd_index);
		ft_putstr_nl(":");
		cmd_part_index = 0;
		while (cmd_builder->cmds[cmd_index][cmd_part_index] != NULL)
		{
			ft_puti(cmd_part_index);
			ft_putstr(" - ");
			ft_putstr_nl(cmd_builder->cmds[cmd_index][cmd_part_index]);
			cmd_part_index++;
		}
		cmd_index++;
	}
}
