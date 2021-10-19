/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:22:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/19 13:23:05 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(t_cmd_builder *cmd_builder)
{
	next_cmd_part(cmd_builder);
	cmd_builder->cmd_part = ft_append_char_to_str(
			cmd_builder->cmd_part, '|');
	next_cmd(cmd_builder);
}
