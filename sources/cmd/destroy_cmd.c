/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:10:32 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 15:16:20 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*destroy_cmd(t_cmd *cmd)
{
	if (cmd != NULL)
		ft_destroy_string_array(&cmd->args);
	free(cmd);
	return (NULL);
}
