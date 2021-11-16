/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:38:47 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/16 15:59:17 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_builtin(t_shell *shell, char **cmd)
{
	size_t	index;

	index = 1;
	while (cmd[index] != NULL)
	{
		if (is_alpha(cmd[index][0]) || cmd[index][0] == '_')
			unset_env_var(shell, cmd[index]);
		else
		{
			put_error("export", cmd[index], "not a valid identifier");
			errno = 1;
			return ;
		}
		index++;
	}
	errno = 0;
}
