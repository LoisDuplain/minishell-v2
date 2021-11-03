
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:41:15 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/03 12:32:22 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	redir(int from, char *to, int mode)
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
	ft_putstr_nl("Eh beh ca va ?");
	dup2(backup_fd, from);
	close(backup_fd);
}

int	get_output_redirection_mode(char *redirection)
{
	if (ft_strcmp(redirection, ">>") == 0)
		return (O_APPEND);
	else if (ft_strcmp(redirection, ">") == 0)
		return (O_TRUNC);
	return (0);
} */

void	process_cmd(t_shell *shell, char **cmd, size_t cmd_len)
{
	char	**args;
	size_t	cmd_part_index;

	args = NULL;
	cmd_part_index = 0;
	while (cmd_part_index < cmd_len)
	{
		/* if (ft_strcmp(cmd[cmd_part_index], ">>") == 0 || ft_strcmp(cmd[cmd_part_index], ">") == 0)
		{
			cmd_part_index++;
			if (cmd_part_index >= cmd_len)
				break ; // TODO: handle error
			redir(STDOUT_FILENO, cmd[cmd_part_index], get_output_redirection_mode(cmd[cmd_part_index - 1]));
		}
		else */
		// if (ft_strcmp(cmd[cmd_part_index], "|") != 0)
			args = ft_add_str_to_str_array(args,
					get_processed_arg(shell, cmd[cmd_part_index]), TRUE);
		cmd_part_index++;
	}
	execute_cmd(shell, args);
	ft_destroy_string_array(&args);
}
