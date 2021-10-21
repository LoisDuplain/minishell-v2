/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/21 18:14:35 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_shell *shell)
{
	t_cmd_builder	*cmd_builder;
	char			current_char;

	cmd_builder = create_cmd_builder(shell->line);
	if (cmd_builder == NULL)
	{
		ft_putstr_nl("cmd_builder creation failed.");
		return ;
	}
	while (cmd_builder->readed_index < ft_strlen(cmd_builder->line))
	{
		current_char = cmd_builder->line[cmd_builder->readed_index];
		dispatch_parsing(cmd_builder, current_char);
		cmd_builder->readed_index++;
	}
	next_cmd(cmd_builder);
	/*
	**	TODO: remove line below
	*/
	display_cmd_builder(cmd_builder);
	/*
	**	TODO: process ne doit pas etre appele ici
	*/
	process_cmds(shell, cmd_builder);
	destroy_cmd_builder(&cmd_builder);
}
