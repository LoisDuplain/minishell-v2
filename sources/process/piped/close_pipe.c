/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:06:20 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 19:06:32 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(t_cmd *cmd)
{
	close(cmd->pipe[1]);
	if (cmd->piped && cmd->next == NULL)
		close(cmd->pipe[0]);
}
