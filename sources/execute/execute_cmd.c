/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:18:07 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 15:33:29 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(t_shell *shell, t_cmd *cmd)
{
	char	*program;
	char	*program_path;

	if (cmd->args == NULL)
		return ;
	program = ft_tolower(cmd->args[0]);
	if (get_builtin(program) != NULL)
		get_builtin(program)(shell, cmd->args);
	else if (ft_contains_char(program, '/'))
	{
		if (program_exists_at(NULL, program))
			execute_program(shell, program, cmd);
		else
			put_error("minishell", "no such file or directory",
				cmd->args[0]);
	}
	else
	{
		program_path = get_program_path(shell, cmd->args[0]);
		execute_program(shell, program_path, cmd);
		free(program_path);
	}
}
