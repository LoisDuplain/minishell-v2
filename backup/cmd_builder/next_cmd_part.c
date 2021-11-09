/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:11:43 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 16:50:19 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	next_cmd_part(t_cmd_builder *cmd_builder)
{
	if (cmd_part)
	cmd_builder->cmd = ft_add_str_to_str_array(cmd_builder->cmd,
			cmd_builder->cmd_part, TRUE);
	cmd_builder->cmd_part = NULL;
}
