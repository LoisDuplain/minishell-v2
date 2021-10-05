/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:38:47 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/05 12:50:37 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_builtin(t_shell *shell, char **cmd)
{
	size_t	index;

	index = 1;
	while (cmd[index] != NULL)
	{
		unset_env_var(shell, cmd[index]);
		index++;
	}
}
