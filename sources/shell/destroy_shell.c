/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 20:07:44 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 13:47:20 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*destroy_shell(t_shell *shell)
{
	if (shell != NULL)
	{
		shell->env = ft_destroy_string_array(&shell->env);
		free(shell->prompt);
		shell->prompt = NULL;
		destroy_cmd_container(&shell->cmd_container);
	}
	return (NULL);
}
