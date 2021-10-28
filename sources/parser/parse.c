/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/28 14:50:59 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	all_quotes_are_closed(char *str)
{
	t_bool	is_open;
	size_t	str_len;
	size_t	index;
	char	current_quote;

	is_open = FALSE;
	str_len = ft_strlen(str);
	index = 0;
	while (index < str_len)
	{
		if (str[index] == '\'' || str[index] == '\"')
		{
			is_open = TRUE;
			current_quote = str[index];
			index++;
			while (index < str_len && str[index] != current_quote)
				index++;
			if (str[index] == current_quote)
				is_open = FALSE;
		}
		index++;
	}
	return (!is_open);
}

void	parse(t_shell *shell)
{
	t_cmd_builder	*cmd_builder;
	char			current_char;

	if (!all_quotes_are_closed(shell->line))
	{
		ft_putstr_nl("error: unclosed quote detected.");
		return ;
	}
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
