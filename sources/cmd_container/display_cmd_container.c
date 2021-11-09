/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_cmd_container.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:40:45 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 13:59:55 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_cmd_container(t_cmd_container *cmd_container)
{
	t_cmd	*current;

	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		display_cmd(current);
		current = current->next;
	}
}
