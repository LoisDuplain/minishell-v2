/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:21:19 by lduplain          #+#    #+#             */
/*   Updated: 2021/11/25 15:21:29 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell			shell;
	t_cmd_container	*cmd_container;

	(void)argv;
	shell = create_shell(env);
	g_shell = &shell;
	if (argc != 1)
		exit_shell(&shell, "Wrong number of arguments.", 1);
	cmd_container = &shell.cmd_container;
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, SIG_IGN);
	while (TRUE)
	{
		set_line(cmd_container, readline(shell.prompt));
		if (cmd_container->line == NULL)
			exit_shell(&shell, "Goodbye :)", 0);
		if (ft_strlen(cmd_container->line) > 0)
		{
			add_history(cmd_container->line);
			if (!tokenize(cmd_container))
				continue ;
			process_cmds(&shell, cmd_container);
		}
	}
	return (0);
}
