/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:22:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 16:26:20 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(t_cmd_container *cmd_container)
{
	next_cmd(cmd_container);
	cmd_container->cmds[get_cmds_size(cmd_container) - 1]->piped = TRUE;
}
