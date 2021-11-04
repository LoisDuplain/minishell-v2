/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:41:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/04 14:50:46 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	stop_output_redir(t_shell *shell)
{
	if (shell->fd_backup == -1)
		return ;
	dup2(shell->fd_backup, shell->fd_replaced);
	close(shell->fd_backup);
	shell->fd_backup = -1;
	shell->fd_replaced = -1;
}
void	start_output_redir(t_shell *shell, int from_fd, int to_fd)
{
	if (shell->fd_backup != -1)
		stop_output_redir(shell);
	shell->fd_replaced = from_fd;
	shell->fd_backup = dup(from_fd);
	dup2(to_fd, from_fd);
	close(to_fd);
}
void	redirect_output_to_file(t_shell *shell, int from_fd, char *to_file, int mode)
{
	int	to_fd;

	to_fd = open(to_file, O_WRONLY | mode | O_CREAT, 0644);
	if (to_fd == -1) // TODO: handle error
		return ;
	start_output_redir(shell, from_fd, to_fd);
}
int	get_output_redirection_mode(char *redirection)
{
	if (ft_strcmp(redirection, ">>") == 0)
		return (O_APPEND);
	else if (ft_strcmp(redirection, ">") == 0)
		return (O_TRUNC);
	return (0);
}

void	redirect_file_to_stdin(t_shell *shell, char *from_file)
{
	int	from_fd;

	if (shell->fd_backup == -1)
		return ;
	from_fd = open(from_file, O_RDONLY);
	shell->fd_replaced = 0;
	shell->fd_backup = dup(0);
	dup2(from_fd, 0);
	close(from_fd);
}

void	process_cmd(t_shell *shell, char **cmd, size_t cmd_len)
{
	char	**args;
	size_t	cmd_part_index;

	args = NULL;
	cmd_part_index = 0;
	while (cmd_part_index < cmd_len)
	{
		if (ft_strcmp(cmd[cmd_part_index], ">>") == 0 || ft_strcmp(cmd[cmd_part_index], ">") == 0)
		{
			cmd_part_index++;
			if (cmd_part_index >= cmd_len)
			{
				put_error("minishell", "syntax error", "missing redir. target");
				ft_destroy_string_array(&args);
				return ;
			}
			redirect_output_to_file(shell, STDOUT_FILENO, cmd[cmd_part_index], get_output_redirection_mode(cmd[cmd_part_index - 1]));
		}
		else if (ft_strcmp(cmd[cmd_part_index], "<") == 0)
		{
			cmd_part_index++;
			if (cmd_part_index >= cmd_len)
			{
				put_error("minishell", "syntax error", "missing redir. input");
				ft_destroy_string_array(&args);
				return ;
			}
			redirect_file_to_stdin(shell, cmd[cmd_part_index]);
		}
		else if (ft_strcmp(cmd[cmd_part_index], "|") != 0)
			args = ft_add_str_to_str_array(args,
					get_processed_arg(shell, cmd[cmd_part_index]), TRUE);
		cmd_part_index++;
	}
	execute_cmd(shell, args);
	stop_output_redir(shell);
	ft_destroy_string_array(&args);
}
