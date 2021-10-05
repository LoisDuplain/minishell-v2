/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/05 15:54:53 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (cmd_builder->line[cmd_builder->readed_index] == ' ')
		{
			next_cmd_part(cmd_builder);
			cmd_builder->readed_index++;
			continue ;
		}
		if (cmd_builder->line[cmd_builder->readed_index] == '|')
		{
			next_cmd(cmd_builder);
			cmd_builder->readed_index++;
			continue ;
		}
		if (cmd_builder->line[cmd_builder->readed_index] == ';')
		{
			next_cmd(cmd_builder);
			cmd_builder->readed_index++;
			continue ;
		}
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

/* void	parse(t_shell *shell)
{
	char	*cmd_part;
	size_t	line_length;
	size_t	index;

	cmd = NULL;
	cmd_part = NULL;
	line_length = ft_strlen(shell->line);
	index = 0;
	while (index < line_length)
	{
		if (shell->line[index] == '"' || shell->line[index] == '\'')
		{
			index = parse_quotes(shell->line, index + 1, shell->line[index], &cmd_part);
			continue ;
		}
		if (shell->line[index] == ' ')
		{
			cmd = ft_add_str_to_str_array(cmd, cmd_part, TRUE);
			cmd_part = NULL;
			index++;
			continue ;
		}
		cmd_part = ft_append_char_to_str(cmd_part, shell->line[index]);
		index++;
	}
	cmd = ft_add_str_to_str_array(cmd, cmd_part, TRUE);

	index = 0;
	while (index < ft_get_string_array_length(cmd))
	{
		printf("-%s-\n", cmd[index]);
		index++;
	}

	ft_destroy_splitted(&cmd);
} */
