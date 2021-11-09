/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_cmd_part.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:29:44 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 13:30:25 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	next_cmd_part(t_cmd_container *cmd_container)
{
	cmd_container->cmd = ft_add_str_to_str_array(cmd_container->cmd,
			cmd_container->cmd_part, TRUE);
	cmd_container->cmd_part = NULL;
}
