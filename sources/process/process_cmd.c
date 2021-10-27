/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:41:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/27 15:57:00 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir(int from, char *to, int mode)
{
	int	to_fd;
	int	backup_fd;

	to_fd = open(to, O_WRONLY | mode | O_CREAT, 0644);
	if (to_fd == -1) // TODO: handle error
		return ;
	backup_fd = dup(from);
	dup2(to_fd, from);
	close(to_fd);
	// TODO: Do action
	dup2(backup_fd, from);
	close(backup_fd);
}

void	process_cmd(t_shell *shell, char **cmd, size_t cmd_len)
{
	char	**args;
	size_t	cmd_part_index;
	int		fd;
	int		backup;

	args = NULL;
	cmd_part_index = 0;
	while (cmd_part_index < cmd_len)
	{
		if (ft_strcmp(cmd[cmd_part_index], ">>") == 0 || ft_strcmp(cmd[cmd_part_index], ">") == 0)
		{
			cmd_part_index++;
			if (cmd_part_index >= cmd_len)
				break ;
			if (ft_strcmp(cmd[cmd_part_index - 1], ">>") == 0)
				fd = open(cmd[cmd_part_index], O_WRONLY | O_APPEND | O_CREAT, 0644);
			else
				fd = open(cmd[cmd_part_index], O_WRONLY | O_TRUNC | O_CREAT, 0644);
			if (fd == -1)
				break ;
			backup = dup(STDOUT_FILENO);
			dup2(fd, STDOUT_FILENO);
			close(fd);
		}
		else
			args = ft_add_str_to_str_array(args,
					get_processed_arg(shell, cmd[cmd_part_index]), TRUE);
		cmd_part_index++;
	}
	// TODO: Builtin or program
	if (get_builtin(ft_tolower(args[0])) != NULL)
		get_builtin(ft_tolower(args[0]))(shell, args);
	// -----------------

	// TEST
	/* dup2(backup, STDOUT_FILENO);
	close(backup); */

	ft_destroy_string_array(&args);
}
