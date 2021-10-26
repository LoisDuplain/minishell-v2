/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduplain <lduplain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:21:19 by lduplain          #+#    #+#             */
/*   Updated: 2021/10/21 22:30:46 by lduplain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(t_shell *shell, char *message)
{
	ft_putstr_nl("exit");
	if (message != NULL)
	{
		ft_putstr("\033[0;31m");
		ft_putstr(message);
		ft_putstr_nl("\033[0m");
	}
	destroy_shell(&shell);
	exit(0);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;

	(void)argv;
	shell = create_shell(env);
	if (shell == NULL)
		exit_shell(shell, "Shell creation failed.");
	if (argc != 1)
		exit_shell(shell, "Wrong number of arguments.");
	signal(SIGINT, ctrl_c_signal);
	signal(SIGQUIT, ctrl_backslash_signal);
	while (TRUE)
	{
		set_line(shell, readline(shell->prompt));
		if (shell->line == NULL || ft_strcmp(shell->line, "exit") == 0)
			exit_shell(shell, "Goodbye :)");
		if (ft_strlen(shell->line) > 0)
		{
			add_history(shell->line);
			parse(shell);
		}
	}
	return (0);
}
