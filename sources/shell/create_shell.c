/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain < lduplain@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 22:28:42 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/24 16:05:15 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	create_shell(char **env)
{
	t_shell	shell;

	shell.env = create_env(env);
	shell.prompt = NULL;
	set_env_var(&shell, "PWD", getcwd(NULL, 0), TRUE);
	update_prompt(&shell);
	init_cmd_container(&shell.cmd_container);
	shell.is_in_execution = FALSE;
	return (shell);
}
