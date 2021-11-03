/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:28:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 17:12:23 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*create_shell(char **env)
{
	t_shell	*shell;

	shell = ft_calloc(1, sizeof(t_shell));
	if (shell == NULL)
		return (NULL);
	shell->env = create_env(env);
	if (shell->env == NULL)
		return (destroy_shell(&shell));
	set_env_var(shell, "PWD", getcwd(NULL, 0), TRUE);
	update_prompt(shell);
	shell->line = NULL;
	shell->cmd = NULL;
	shell->fd_backup = -1;
	shell->fd_replaced = -1;
	return (shell);
}
