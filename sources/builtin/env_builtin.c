/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 13:12:08 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/05 15:40:06 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_builtin(t_shell *shell, char **cmd)
{
	size_t	index;

	(void)cmd;
	index = 1;
	while (shell->env[index] != NULL)
	{
		if (ft_contains_char(shell->env[index], '='))
			ft_putstr_nl(shell->env[index]);
		index++;
	}
}
