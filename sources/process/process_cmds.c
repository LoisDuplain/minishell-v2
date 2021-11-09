/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:07:24 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/09 16:31:26 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* size_t	preprocess_cmd(t_shell *shell, char ***cmds, size_t pipe_index)
{
	size_t	count;
	char	**cmd;
	size_t	cmd_size;

	count = 1;
	cmd = cmds[pipe_index];
	cmd_size = ft_get_string_array_length(cmd);
	if (pipe_index > 0)
		start_shell_redirection(&shell->in_redir, STDIN_FILENO, shell->pipe[0]);
	if (ft_strcmp(cmd[cmd_size - 1], "|") == 0 && cmds[pipe_index + 1] != NULL)
		start_shell_redirection(&shell->out_redir, STDOUT_FILENO, shell->pipe[1]);
	process_cmd(shell, cmd, cmd_size);
	if (ft_strcmp(cmd[cmd_size - 1], "|") == 0 && cmds[pipe_index + 1] != NULL)
		count += preprocess_cmd(shell, cmds, pipe_index + 1);
	return (count);
} */

void	process_cmds(t_shell *shell, t_cmd_container *cmd_container)
{
	t_cmd	*current;

	if (get_cmds_size(cmd_container) <= 0)
		return ;
	current = cmd_container->cmds[0];
	while (current != NULL)
	{
		/* if (ft_strcmp(cmd[cmd_size - 1], "|") == 0)
		{
			if (pipe(shell->pipe) == -1)
				return ;
			cmd_index += preprocess_cmd(shell, &cmd_builder->cmds[cmd_index], 0);
			stop_shell_redirection(&shell->out_redir);
			stop_shell_redirection(&shell->in_redir);
		}
		else
		{ */
			process_cmd(shell, current);
			stop_shell_redirection(&shell->out_redir);
			stop_shell_redirection(&shell->in_redir);
			current = current->next;
		/* } */
	}
}
