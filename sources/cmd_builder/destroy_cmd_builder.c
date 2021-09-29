/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_cmd_builder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:36:54 by lduplain          #+#    #+#             */
/*   Updated: 2021/09/29 16:44:52 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*destroy_cmd_builder(t_cmd_builder **cmd_builder)
{
	size_t	index;

	if (*cmd_builder != NULL)
	{
		if ((*cmd_builder)->cmds != NULL)
		{
			index = 0;
			while ((*cmd_builder)->cmds[index] != NULL)
			{
				ft_destroy_string_array(&(*cmd_builder)->cmds[index]);
				index++;
			}
			free((*cmd_builder)->cmds);
			(*cmd_builder)->cmds = NULL;
		}
		ft_destroy_string_array(&(*cmd_builder)->cmd);
		free((*cmd_builder)->cmd_part);
		(*cmd_builder)->cmd_part = NULL;
		free(*cmd_builder);
		*cmd_builder = NULL;
	}
	return (NULL);
}
