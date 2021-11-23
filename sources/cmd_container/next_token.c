/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:29:44 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/23 10:04:22 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	next_token(t_cmd_container *cmd_container)
{
	if (cmd_container->token == NULL)
		return ;
	cmd_container->tokens = ft_add_str_to_str_array(cmd_container->tokens,
			cmd_container->token, TRUE);
	cmd_container->token = NULL;
}
