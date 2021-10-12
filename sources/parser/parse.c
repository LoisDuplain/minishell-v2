/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/12 15:02:32 by lduplain         ###   ########.fr       */
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

void	parse_redirection(t_cmd_builder *cmd_builder, char redirect)
{
	
}

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
		if (current_char == '\'' || current_char == '\"')
			parse_quotes(cmd_builder, current_char);
		else if (current_char == '<' || current_char == '>')
			parse_redirection(cmd_builder, current_char);
		else if (current_char == ' ')
			next_cmd_part(cmd_builder);
		else if (current_char == ';')
			next_cmd(cmd_builder);
		else
			cmd_builder->cmd_part = ft_append_char_to_str(
					cmd_builder->cmd_part, current_char);
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
