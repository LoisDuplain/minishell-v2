/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_builder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:30:23 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 11:58:45 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd_builder	*create_cmd_builder(char *line)
{
	t_cmd_builder	*cmd_builder;

	cmd_builder = ft_calloc(1, sizeof(t_cmd_builder));
	if (cmd_builder == NULL)
		return (NULL);
	cmd_builder->line = line;
	cmd_builder->readed_index = 0;
	cmd_builder->cmds = NULL;
	cmd_builder->cmd = NULL;
	cmd_builder->cmd_part = NULL;
	return (cmd_builder);
}
