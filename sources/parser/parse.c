/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/06 13:25:42 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
**	TODO:
**	- Parse space
**	- Parse simple quotes
**	- Parse double quotes
**	- Parse pipes
**	- Parse redirections
**	- Parse semicolons
*/

void	parse_quotes(t_cmd_builder *cmd_builder, char quote)
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

void	parse(t_shell *shell)
{
	t_cmd_builder	*cmd_builder;

	cmd_builder = create_cmd_builder(shell->line);
	if (cmd_builder == NULL)
	{
		ft_putstr_nl("cmd_builder creation failed.");
		return ;
	}
	while (cmd_builder->readed_index < ft_strlen(cmd_builder->line))
	{
		if (cmd_builder->line[cmd_builder->readed_index] == '\'')
			parse_quotes(cmd_builder, '\'');
		else if (cmd_builder->line[cmd_builder->readed_index] == '\"')
			parse_quotes(cmd_builder, '\"');
		else if (cmd_builder->line[cmd_builder->readed_index] == ' ')
			next_cmd_part(cmd_builder);
		else if (cmd_builder->line[cmd_builder->readed_index] == ';')
			next_cmd(cmd_builder);
		else
			cmd_builder->cmd_part = ft_append_char_to_str(cmd_builder->cmd_part, cmd_builder->line[cmd_builder->readed_index]);
		cmd_builder->readed_index++;
	}
	next_cmd(cmd_builder);
	/*
	**	DEBUG
	*/
	int i = 0;
	while (cmd_builder->cmds[i] != NULL)
	{
		ft_putstr("Command ");
		ft_puti(i);
		ft_putstr_nl(":");
		int j = 0;
		while (cmd_builder->cmds[i][j] != NULL)
		{
			ft_puti(j);
			ft_putstr(" - ");
			ft_putstr_nl(cmd_builder->cmds[i][j]);
			j++;
		}
		i++;
	}
	/*
	**	DEBUG
	*/
	destroy_cmd_builder(&cmd_builder);
}
