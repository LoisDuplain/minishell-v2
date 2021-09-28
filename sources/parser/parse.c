/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:13:57 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/28 13:05:58 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse(t_shell *shell)
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
}
